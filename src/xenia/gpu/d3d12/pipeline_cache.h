/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2018 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_GPU_D3D12_PIPELINE_CACHE_H_
#define XENIA_GPU_D3D12_PIPELINE_CACHE_H_

#include <unordered_map>

#include "third_party/xxhash/xxhash.h"

#include "xenia/gpu/d3d12/d3d12_shader.h"
#include "xenia/gpu/register_file.h"
#include "xenia/gpu/shader_translator.h"
#include "xenia/gpu/xenos.h"
#include "xenia/ui/d3d12/d3d12_context.h"

namespace xe {
namespace gpu {
namespace d3d12 {

class PipelineCache {
 public:
  enum class UpdateStatus {
    kCompatible,
    kMismatch,
    kError,
  };

  PipelineCache(RegisterFile* register_file, ui::d3d12::D3D12Context* context);
  ~PipelineCache();

  void Shutdown();

  D3D12Shader* LoadShader(ShaderType shader_type, uint32_t guest_address,
                          const uint32_t* host_address, uint32_t dword_count);

  UpdateStatus ConfigurePipeline(D3D12Shader* vertex_shader,
                                 D3D12Shader* pixel_shader,
                                 PrimitiveType primitive_type,
                                 IndexFormat index_format,
                                 ID3D12PipelineState** pipeline_out,
                                 ID3D12RootSignature** root_signature_out);

  void ClearCache();

  enum class RootParameter {
    // These are always present.

    // Most frequently changed (for one object drawn multiple times, for
    // instance - may contain projection matrices, also vertex offsets for
    // objects drawn in multiple parts).
    // This constants 8 pages of float constants (b2-b9) and fetch constants
    // (b10).
    kVertexConstants,
    // Less frequently changed (per-material) - 8 pages of float constants
    // (b2-b9).
    kPixelConstants,
    // Rarely changed - system constants like viewport and alpha testing (b0)
    // and loop and bool constants (b1).
    kCommonConstants,
    // Never changed - shared memory byte address buffer (t0, space1).
    kVirtualMemory,

    kCountNoTextures,

    // These are there only if textures are fetched (they are changed pretty
    // frequently, but for the ease of maintenance they're in the end).
    // If the pixel shader samples textures, these are for pixel textures
    // (changed more frequently), otherwise, if the vertex shader samples
    // textures, these are for vertex textures.

    // Used textures of all types (t0+, space0).
    kPixelOrVertexTextures = kCountNoTextures,
    // Used samplers (s0+).
    kPixelOrVertexSamplers,

    kCountWithOneStageTextures,

    // These are only present if both pixel and vertex shaders sample textures
    // for vertex textures.

    // Used textures of all types (t0+, space0).
    kVertexTextures = kCountWithOneStageTextures,
    // Used samplers (s0+).
    kVertexSamplers,

    kCountWithTwoStageTextures,
  };

 private:
  bool SetShadowRegister(uint32_t* dest, uint32_t register_name);
  bool SetShadowRegister(float* dest, uint32_t register_name);

  bool TranslateShader(D3D12Shader* shader, xenos::xe_gpu_program_cntl_t cntl);

  UpdateStatus UpdateState(D3D12Shader* vertex_shader,
                           D3D12Shader* pixel_shader,
                           PrimitiveType primitive_type,
                           IndexFormat index_format);

  // pRootSignature, VS, PS, DS, HS, GS, PrimitiveTopologyType.
  UpdateStatus UpdateShaderStages(D3D12Shader* vertex_shader,
                                  D3D12Shader* pixel_shader,
                                  PrimitiveType primitive_type);
  // BlendState, SampleMask.
  UpdateStatus UpdateBlendState(D3D12Shader* pixel_shader);
  // RasterizerState.
  UpdateStatus UpdateRasterizerState(PrimitiveType primitive_type);
  // DepthStencilState.
  UpdateStatus UpdateDepthStencilState();
  // IBStripCutValue.
  UpdateStatus UpdateIBStripCutValue(IndexFormat index_format);
  // NumRenderTargets, RTVFormats, DSVFormat.
  UpdateStatus UpdateRenderTargetFormats();

  RegisterFile* register_file_ = nullptr;
  ui::d3d12::D3D12Context* context_ = nullptr;

  // Reusable shader translator.
  std::unique_ptr<ShaderTranslator> shader_translator_ = nullptr;
  // All loaded shaders mapped by their guest hash key.
  std::unordered_map<uint64_t, D3D12Shader*> shader_map_;

  // Root signatures for different descriptor counts.
  std::unordered_map<uint32_t, ID3D12RootSignature*> root_signatures_;
  ID3D12RootSignature* GetRootSignature(const D3D12Shader* vertex_shader,
                                        const D3D12Shader* pixel_shader);

  // Hash state used to incrementally produce pipeline hashes during update.
  // By the time the full update pass has run the hash will represent the
  // current state in a way that can uniquely identify the produced
  // ID3D12PipelineState.
  XXH64_state_t hash_state_;
  struct Pipeline {
    ID3D12PipelineState* state;
    // From root_signatures_ - not owned.
    ID3D12RootSignature* root_signature;
  };
  // All previously generated pipelines mapped by hash.
  std::unordered_map<uint64_t, Pipeline*> pipelines_;
  // Sets StreamOutput, InputLayout, SampleDesc, NodeMask, CachedPSO, Flags.
  Pipeline* GetPipeline(uint64_t hash_key);

  // Previously used pipeline. This matches our current state settings
  // and allows us to quickly(ish) reuse the pipeline if no registers have
  // changed.
  Pipeline* current_pipeline_ = nullptr;

  // Description of the pipeline being created.
  D3D12_GRAPHICS_PIPELINE_STATE_DESC update_desc_;

  struct UpdateShaderStagesRegisters {
    D3D12Shader* vertex_shader;
    D3D12Shader* pixel_shader;
    uint32_t sq_program_cntl;
    bool primitive_topology_is_line;

    UpdateShaderStagesRegisters() { Reset(); }
    void Reset() { std::memset(this, 0, sizeof(*this)); }
  } update_shader_stages_regs_;

  struct UpdateBlendStateRegisters {
    // RB_COLOR_MASK with unused render targets removed.
    uint32_t color_mask;
    // Blend control updated only for used render targets.
    uint32_t blendcontrol[4];
    bool colorcontrol_blend_enable;

    UpdateBlendStateRegisters() { Reset(); }
    void Reset() { std::memset(this, 0, sizeof(*this)); }
  } update_blend_state_regs_;

  struct UpdateRasterizerStateRegisters {
    // Polygon offset is in Xenos units.
    float poly_offset;
    float poly_offset_scale;
    uint8_t cull_mode;
    bool fill_mode_wireframe;
    bool front_counter_clockwise;
    bool depth_clamp_enable;

    UpdateRasterizerStateRegisters() { Reset(); }
    void Reset() { std::memset(this, 0, sizeof(*this)); }
  } update_rasterizer_state_regs_;

  struct UpdateDepthStencilStateRegisters {
    uint32_t rb_depthcontrol;
    uint32_t rb_stencilrefmask;

    UpdateDepthStencilStateRegisters() { Reset(); }
    void Reset() { std::memset(this, 0, sizeof(*this)); }
  } update_depth_stencil_state_regs_;

  struct UpdateIBStripCutValueRegisters {
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE ib_strip_cut_value;

    UpdateIBStripCutValueRegisters() { Reset(); }
    void Reset() { std::memset(this, 0, sizeof(*this)); }
  } update_ib_strip_cut_value_regs_;
};

}  // namespace d3d12
}  // namespace gpu
}  // namespace xe

#endif  // XENIA_GPU_D3D12_PIPELINE_CACHE_H_
