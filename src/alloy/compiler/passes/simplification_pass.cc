/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include <alloy/compiler/passes/simplification_pass.h>

using namespace alloy;
using namespace alloy::compiler;
using namespace alloy::compiler::passes;
using namespace alloy::hir;


SimplificationPass::SimplificationPass() :
    CompilerPass() {
}

SimplificationPass::~SimplificationPass() {
}

int SimplificationPass::Run(HIRBuilder* builder) {
  EliminateConversions(builder);
  SimplifyAssignments(builder);
  return 0;
}

void SimplificationPass::EliminateConversions(HIRBuilder* builder) {
  // First, we check for truncates/extensions that can be skipped.
  // This generates some assignments which then the second step will clean up.
  // Only zero extend truncates can be skipped:
  //   v1.i32 = truncate v0.i64
  //   v2.i64 = zero_extend v1.i32
  // becomes:
  //   v1.i32 = truncate v0.i64 (may be dead code removed later)
  //   v2.i64 = v0.i64
  // But both zero/sign extends can be skipped:
  //   v1.i64 = zero/sign_extend v0.i32
  //   v2.i32 = truncate v1.i64
  // becomes:
  //   v1.i64 = zero/sign_extend v0.i32 (may be dead code removed later)
  //   v2.i32 = v0.i32

  auto block = builder->first_block();
  while (block) {
    auto i = block->instr_head;
    while (i) {
      // To make things easier we check in reverse (source of truncate/extend
      // back to definition).
      if (i->opcode == &OPCODE_TRUNCATE_info) {
        // Matches zero/sign_extend + truncate.
        CheckTruncate(i);
      } else if (i->opcode == &OPCODE_ZERO_EXTEND_info) {
        // Matches truncate + zero_extend.
        CheckZeroExtend(i);
      }
      i = i->next;
    }
    block = block->next;
  }
}

void SimplificationPass::CheckTruncate(Instr* i) {
  // Walk backward up src's chain looking for an extend. We may have
  // assigns, so skip those.
  auto src = i->src1.value;
  Instr* def = src->def;
  while (def && def->opcode == &OPCODE_ASSIGN_info) {
    // Skip asignments.
    def = def->src1.value->def;
  }
  if (def) {
    if (def->opcode == &OPCODE_SIGN_EXTEND_info) {
      // Value comes from a sign extend.
      if (def->src1.value->type == i->dest->type) {
        // Types match, use original by turning this into an assign.
        i->Replace(&OPCODE_ASSIGN_info, 0);
        i->set_src1(def->src1.value);
      }
    } else if (def->opcode == &OPCODE_ZERO_EXTEND_info) {
      // Value comes from a zero extend.
      if (def->src1.value->type == i->dest->type) {
        // Types match, use original by turning this into an assign.
        i->Replace(&OPCODE_ASSIGN_info, 0);
        i->set_src1(def->src1.value);
      }
    }
  }
}

void SimplificationPass::CheckZeroExtend(Instr* i) {
  // Walk backward up src's chain looking for a truncate. We may have
  // assigns, so skip those.
  auto src = i->src1.value;
  Instr* def = src->def;
  while (def && def->opcode == &OPCODE_ASSIGN_info) {
    // Skip asignments.
    def = def->src1.value->def;
  }
  if (def && def->opcode == &OPCODE_TRUNCATE_info) {
    // Value comes from a truncate.
    if (def->src1.value->type == i->dest->type) {
      // Types match, use original by turning this into an assign.
      i->Replace(&OPCODE_ASSIGN_info, 0);
      i->set_src1(def->src1.value);
    }
  }
}

void SimplificationPass::SimplifyAssignments(HIRBuilder* builder) {
  // Run over the instructions and rename assigned variables:
  //   v1 = v0
  //   v2 = v1
  //   v3 = add v0, v2
  // becomes:
  //   v1 = v0
  //   v2 = v0
  //   v3 = add v0, v0
  // This could be run several times, as it could make other passes faster
  // to compute (for example, ConstantPropagation). DCE will take care of
  // the useless assigns.
  //
  // We do this by walking each instruction. For each value op we
  // look at its def instr to see if it's an assign - if so, we use the src
  // of that instr. Because we may have chains, we do this recursively until
  // we find a non-assign def.

  auto block = builder->first_block();
  while (block) {
    auto i = block->instr_head;
    while (i) {
      uint32_t signature = i->opcode->signature;
      if (GET_OPCODE_SIG_TYPE_SRC1(signature) == OPCODE_SIG_TYPE_V) {
        i->set_src1(CheckValue(i->src1.value));
      }
      if (GET_OPCODE_SIG_TYPE_SRC2(signature) == OPCODE_SIG_TYPE_V) {
        i->set_src2(CheckValue(i->src2.value));
      }
      if (GET_OPCODE_SIG_TYPE_SRC3(signature) == OPCODE_SIG_TYPE_V) {
        i->set_src3(CheckValue(i->src3.value));
      }
      i = i->next;
    }
    block = block->next;
  }
}

Value* SimplificationPass::CheckValue(Value* value) {
  Instr* def = value->def;
  if (def && def->opcode == &OPCODE_ASSIGN_info) {
    // Value comes from an assignment - recursively find if it comes from
    // another assignment. It probably doesn't, if we already replaced it.
    Value* replacement = def->src1.value;
    while (true) {
      def = replacement->def;
      if (!def || def->opcode != &OPCODE_ASSIGN_info) {
        break;
      }
      replacement = def->src1.value;
    }
    return replacement;
  }
  return value;
}
