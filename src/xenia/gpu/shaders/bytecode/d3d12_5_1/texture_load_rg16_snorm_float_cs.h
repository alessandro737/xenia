#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer xe_texture_load_constants
// {
//
//   uint xe_texture_load_is_tiled_3d_endian_scale;// Offset:    0 Size:     4
//   uint xe_texture_load_guest_offset; // Offset:    4 Size:     4
//   uint xe_texture_load_guest_pitch_aligned;// Offset:    8 Size:     4
//   uint xe_texture_load_guest_z_stride_block_rows_aligned;// Offset:   12 Size:     4
//   uint3 xe_texture_load_size_blocks; // Offset:   16 Size:    12
//   uint xe_texture_load_host_offset;  // Offset:   28 Size:     4
//   uint xe_texture_load_host_pitch;   // Offset:   32 Size:     4
//   uint xe_texture_load_height_texels;// Offset:   36 Size:     4 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      ID      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- ------- -------------- ------
// xe_texture_load_source            texture   uint4         buf      T0             t0      1 
// xe_texture_load_dest                  UAV   uint4         buf      U0             u0      1 
// xe_texture_load_constants         cbuffer      NA          NA     CB0            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_1
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[0:0][3], immediateIndexed, space=0
dcl_resource_buffer (uint,uint,uint,uint) T0[0:0], space=0
dcl_uav_typed_buffer (uint,uint,uint,uint) U0[0:0], space=0
dcl_input vThreadID.xyz
dcl_temps 5
dcl_thread_group 4, 32, 1
ishl r0.x, vThreadID.x, l(3)
mov r0.y, vThreadID.y
uge r0.yz, r0.xxyx, CB0[0][1].xxyx
or r0.y, r0.z, r0.y
if_nz r0.y
  ret 
endif 
ishl r0.x, r0.x, l(2)
imad r0.y, vThreadID.z, CB0[0][1].y, vThreadID.y
imad r0.y, r0.y, CB0[0][2].x, r0.x
iadd r0.y, r0.y, CB0[0][1].w
and r0.z, CB0[0][0].x, l(1)
if_nz r0.z
  and r0.w, CB0[0][0].x, l(2)
  if_nz r0.w
    ishr r1.xyz, vThreadID.yzyy, l(4, 2, 3, 0)
    ushr r2.xy, CB0[0][0].wzww, l(4, 5, 0, 0)
    imad r0.w, r1.y, r2.x, r1.x
    ibfe r1.xw, l(27, 0, 0, 29), l(2, 0, 0, 0), vThreadID.xxxx
    imad r0.w, r0.w, r2.y, r1.x
    ishl r1.x, vThreadID.y, l(10)
    ishr r1.x, r1.x, l(6)
    and r1.x, r1.x, l(96)
    iadd r1.y, r1.y, r1.z
    bfi r1.z, l(1), l(1), r1.y, l(0)
    iadd r1.z, r1.z, r1.w
    bfi r1.z, l(2), l(1), r1.z, l(0)
    bfi r1.y, l(1), l(0), r1.y, r1.z
    bfi r1.zw, l(0, 0, 20, 20), l(0, 0, 10, 13), r0.wwww, l(0, 0, 0, 0)
    imad r1.xz, r1.xxxx, l(2, 0, 16, 0), r1.zzwz
    bfi r1.xz, l(2, 0, 2, 0), l(8, 0, 11, 0), vThreadID.zzzz, r1.xxzx
    bfi r0.w, l(1), l(4), vThreadID.y, l(0)
    ubfe r1.w, l(3), l(6), r1.x
    and r2.x, r1.y, l(6)
    bfi r1.y, l(1), l(8), r1.y, l(0)
    imad r1.y, r1.w, l(32), r1.y
    imad r1.y, r2.x, l(4), r1.y
    bfi r1.xz, l(6, 0, 6, 0), l(0, 0, 3, 0), r0.wwww, r1.xxzx
    bfi r0.w, l(9), l(3), r1.y, r1.z
    bfi r0.w, l(6), l(0), r1.x, r0.w
  else 
    ibfe r1.xy, l(27, 29, 0, 0), l(2, 0, 0, 0), vThreadID.xxxx
    ishr r1.zw, vThreadID.yyyy, l(0, 0, 5, 2)
    ushr r2.x, CB0[0][0].z, l(5)
    imad r1.x, r1.z, r2.x, r1.x
    ishl r2.xy, vThreadID.yyyy, l(5, 7, 0, 0)
    and r2.xy, r2.xyxx, l(448, 2048, 0, 0)
    bfi r1.z, l(23), l(9), r1.x, r2.x
    bfi r2.z, l(1), l(4), vThreadID.y, l(0)
    iadd r1.z, r1.z, r2.z
    ishl r2.xw, r2.xxxx, l(3, 0, 0, 2)
    bfi r2.xw, l(23, 0, 0, 23), l(12, 0, 0, 11), r1.xxxx, r2.xxxw
    imad r2.xz, r2.zzzz, l(8, 0, 4, 0), r2.xxwx
    bfi r1.x, l(12), l(0), r2.y, r2.x
    and r2.x, r2.z, l(1792)
    iadd r1.x, r1.x, r2.x
    and r1.w, r1.w, l(2)
    iadd r1.y, r1.y, r1.w
    bfi r1.y, l(2), l(6), r1.y, l(0)
    iadd r1.x, r1.x, r1.y
    bfi r0.w, l(6), l(0), r1.z, r1.x
  endif 
else 
  imad r1.x, vThreadID.z, CB0[0][0].w, vThreadID.y
  imad r0.w, r1.x, CB0[0][0].z, r0.x
endif 
iadd r0.x, r0.w, CB0[0][0].y
ushr r0.xy, r0.xyxx, l(4, 4, 0, 0)
ubfe r0.w, l(2), l(2), CB0[0][0].x
ld r1.xyzw, r0.xxxx, T0[0].xyzw
ieq r2.xyz, r0.wwww, l(1, 2, 3, 0)
or r2.xy, r2.yzyy, r2.xyxx
if_nz r2.x
  ishl r3.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r3.xyzw, r3.xyzw, l(0xff00ff00, 0xff00ff00, 0xff00ff00, 0xff00ff00)
  ushr r4.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r4.xyzw, r4.xyzw, l(0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff)
  iadd r1.xyzw, r3.xyzw, r4.xyzw
endif 
if_nz r2.y
  ushr r3.xyzw, r1.xyzw, l(16, 16, 16, 16)
  bfi r1.xyzw, l(16, 16, 16, 16), l(16, 16, 16, 16), r1.xyzw, r3.xyzw
endif 
ibfe r3.xyzw, l(16, 16, 16, 16), l(0, 0, 0, 0), r1.xyzw
itof r3.xyzw, r3.xyzw
mul r3.xyzw, r3.xyzw, l(0.000031, 0.000031, 0.000031, 0.000031)
max r3.xyzw, r3.xyzw, l(-1.000000, -1.000000, -1.000000, -1.000000)
ishr r1.xyzw, r1.xyzw, l(16, 16, 16, 16)
itof r1.xyzw, r1.xyzw
mul r1.xyzw, r1.xyzw, l(0.000031, 0.000031, 0.000031, 0.000031)
max r1.xyzw, r1.xyzw, l(-1.000000, -1.000000, -1.000000, -1.000000)
f32tof16 r3.xyzw, r3.xyzw
f32tof16 r1.xyzw, r1.xyzw
imad r1.xyzw, r1.xyzw, l(0x00010000, 0x00010000, 0x00010000, 0x00010000), r3.xyzw
store_uav_typed U0[0].xyzw, r0.yyyy, r1.xyzw
iadd r0.w, r0.y, l(1)
if_nz r0.z
  mov r0.z, l(32)
else 
  mov r0.z, l(16)
endif 
ushr r0.z, r0.z, l(4)
iadd r0.x, r0.z, r0.x
ld r1.xyzw, r0.xxxx, T0[0].xyzw
if_nz r2.x
  ishl r3.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r3.xyzw, r3.xyzw, l(0xff00ff00, 0xff00ff00, 0xff00ff00, 0xff00ff00)
  ushr r4.xyzw, r1.xyzw, l(8, 8, 8, 8)
  and r4.xyzw, r4.xyzw, l(0x00ff00ff, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff)
  iadd r1.xyzw, r3.xyzw, r4.xyzw
endif 
if_nz r2.y
  ushr r2.xyzw, r1.xyzw, l(16, 16, 16, 16)
  bfi r1.xyzw, l(16, 16, 16, 16), l(16, 16, 16, 16), r1.xyzw, r2.xyzw
endif 
ibfe r2.xyzw, l(16, 16, 16, 16), l(0, 0, 0, 0), r1.xyzw
itof r2.xyzw, r2.xyzw
mul r2.xyzw, r2.xyzw, l(0.000031, 0.000031, 0.000031, 0.000031)
max r2.xyzw, r2.xyzw, l(-1.000000, -1.000000, -1.000000, -1.000000)
ishr r1.xyzw, r1.xyzw, l(16, 16, 16, 16)
itof r1.xyzw, r1.xyzw
mul r1.xyzw, r1.xyzw, l(0.000031, 0.000031, 0.000031, 0.000031)
max r1.xyzw, r1.xyzw, l(-1.000000, -1.000000, -1.000000, -1.000000)
f32tof16 r2.xyzw, r2.xyzw
f32tof16 r1.xyzw, r1.xyzw
imad r1.xyzw, r1.xyzw, l(0x00010000, 0x00010000, 0x00010000, 0x00010000), r2.xyzw
store_uav_typed U0[0].xyzw, r0.wwww, r1.xyzw
ret 
// Approximately 128 instruction slots used
#endif

const BYTE texture_load_rg16_snorm_float_cs[] =
{
     68,  88,  66,  67, 231,  56, 
     59,  12, 252,  47,  13, 143, 
    214,  32, 101, 220,  14, 202, 
     71,  49,   1,   0,   0,   0, 
    188,  21,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     32,   4,   0,   0,  48,   4, 
      0,   0,  64,   4,   0,   0, 
     32,  21,   0,   0,  82,  68, 
     69,  70, 228,   3,   0,   0, 
      1,   0,   0,   0, 252,   0, 
      0,   0,   3,   0,   0,   0, 
     60,   0,   0,   0,   1,   5, 
     83,  67,   0,   5,   0,   0, 
    185,   3,   0,   0,  19,  19, 
     68,  37,  60,   0,   0,   0, 
     24,   0,   0,   0,  40,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 203,   0, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 224,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    120, 101,  95, 116, 101, 120, 
    116, 117, 114, 101,  95, 108, 
    111,  97, 100,  95, 115, 111, 
    117, 114,  99, 101,   0, 120, 
    101,  95, 116, 101, 120, 116, 
    117, 114, 101,  95, 108, 111, 
     97, 100,  95, 100, 101, 115, 
    116,   0, 120, 101,  95, 116, 
    101, 120, 116, 117, 114, 101, 
     95, 108, 111,  97, 100,  95, 
     99, 111, 110, 115, 116,  97, 
    110, 116, 115,   0, 171, 171, 
    224,   0,   0,   0,   8,   0, 
      0,   0,  20,   1,   0,   0, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     84,   2,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 132,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 168,   2, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0, 132,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 197,   2,   0,   0, 
      8,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    132,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    233,   2,   0,   0,  12,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 132,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  27,   3, 
      0,   0,  16,   0,   0,   0, 
     12,   0,   0,   0,   2,   0, 
      0,   0,  64,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 100,   3,   0,   0, 
     28,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    132,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    128,   3,   0,   0,  32,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0, 132,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 155,   3, 
      0,   0,  36,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0, 132,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 120, 101,  95, 116, 
    101, 120, 116, 117, 114, 101, 
     95, 108, 111,  97, 100,  95, 
    105, 115,  95, 116, 105, 108, 
    101, 100,  95,  51, 100,  95, 
    101, 110, 100, 105,  97, 110, 
     95, 115,  99,  97, 108, 101, 
      0, 100, 119, 111, 114, 100, 
      0, 171,   0,   0,  19,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 125,   2, 
      0,   0, 120, 101,  95, 116, 
    101, 120, 116, 117, 114, 101, 
     95, 108, 111,  97, 100,  95, 
    103, 117, 101, 115, 116,  95, 
    111, 102, 102, 115, 101, 116, 
      0, 120, 101,  95, 116, 101, 
    120, 116, 117, 114, 101,  95, 
    108, 111,  97, 100,  95, 103, 
    117, 101, 115, 116,  95, 112, 
    105, 116,  99, 104,  95,  97, 
    108, 105, 103, 110, 101, 100, 
      0, 120, 101,  95, 116, 101, 
    120, 116, 117, 114, 101,  95, 
    108, 111,  97, 100,  95, 103, 
    117, 101, 115, 116,  95, 122, 
     95, 115, 116, 114, 105, 100, 
    101,  95,  98, 108, 111,  99, 
    107,  95, 114, 111, 119, 115, 
     95,  97, 108, 105, 103, 110, 
    101, 100,   0, 120, 101,  95, 
    116, 101, 120, 116, 117, 114, 
    101,  95, 108, 111,  97, 100, 
     95, 115, 105, 122, 101,  95, 
     98, 108, 111,  99, 107, 115, 
      0, 117, 105, 110, 116,  51, 
      0, 171, 171, 171,   1,   0, 
     19,   0,   1,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     55,   3,   0,   0, 120, 101, 
     95, 116, 101, 120, 116, 117, 
    114, 101,  95, 108, 111,  97, 
    100,  95, 104, 111, 115, 116, 
     95, 111, 102, 102, 115, 101, 
    116,   0, 120, 101,  95, 116, 
    101, 120, 116, 117, 114, 101, 
     95, 108, 111,  97, 100,  95, 
    104, 111, 115, 116,  95, 112, 
    105, 116,  99, 104,   0, 120, 
    101,  95, 116, 101, 120, 116, 
    117, 114, 101,  95, 108, 111, 
     97, 100,  95, 104, 101, 105, 
    103, 104, 116,  95, 116, 101, 
    120, 101, 108, 115,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  49,  48, 
     46,  49,   0, 171, 171, 171, 
     73,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  79,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  83,  72,  69,  88, 
    216,  16,   0,   0,  81,   0, 
      5,   0,  54,   4,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   7,  70, 142,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  88,   8,   0,   7, 
     70, 126,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  68,  68, 
      0,   0,   0,   0,   0,   0, 
    156,   8,   0,   7,  70, 238, 
     49,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  68,  68,   0,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   2, 114,   0,   2,   0, 
    104,   0,   0,   2,   5,   0, 
      0,   0, 155,   0,   0,   4, 
      4,   0,   0,   0,  32,   0, 
      0,   0,   1,   0,   0,   0, 
     41,   0,   0,   6,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,   2,   0,   1,  64, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   4,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,   2,   0,  80,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0,   6,   1, 
     16,   0,   0,   0,   0,   0, 
      6, 129,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  60,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     21,   0,   0,   1,  41,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,   2,   0, 
     26, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  26,   0, 
      2,   0,  35,   0,   0,  11, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     58, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   9,  66,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  31,   0, 
      4,   3,  58,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0, 150,   5, 
      2,   0,   2,  64,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  85,   0, 
      0,  12,  50,   0,  16,   0, 
      2,   0,   0,   0, 182, 143, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  35,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0, 139,   0, 
      0,  14, 146,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  27,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  29,   0,   0,   0, 
      2,  64,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   2,   0, 
     35,   0,   0,   9, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     41,   0,   0,   6,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,   2,   0,   1,  64, 
      0,   0,  10,   0,   0,   0, 
     42,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  96,   0, 
      0,   0,  30,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  11,  66,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  30,   0,   0,   7, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  11,  66,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0, 140,   0,   0,  11, 
     34,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  20, 194,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  20,   0, 
      0,   0,  20,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  13,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     35,   0,   0,  12,  82,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0, 166,  11, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  16,  82,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
      0,   0,   0,   0, 166,  10, 
      2,   0,   6,   2,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  10, 130,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   4,   0, 
      0,   0,  26,   0,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0, 138,   0,   0,   9, 
    130,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
    140,   0,   0,  11,  34,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      8,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  32,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  35,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   4,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0, 140,   0,   0,  17, 
     82,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,   6,   2,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  11, 130,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
    140,   0,   0,  11, 130,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   6,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  18,   0,   0,   1, 
    139,   0,   0,  14,  50,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,  27,   0, 
      0,   0,  29,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      2,   0,  42,   0,   0,   9, 
    194,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,   2,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   2,   0, 
      0,   0,  85,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  42, 128,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   5,   0, 
      0,   0,  35,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  41,   0,   0,   9, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  86,   5,   2,   0, 
      2,  64,   0,   0,   5,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  10, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0, 192,   1,   0,   0, 
      0,   8,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    140,   0,   0,  11,  66,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,  23,   0, 
      0,   0,   1,  64,   0,   0, 
      9,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0, 140,   0,   0,  10, 
     66,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   4,   0,   0,   0, 
     26,   0,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  41,   0, 
      0,  10, 146,   0,  16,   0, 
      2,   0,   0,   0,   6,   0, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0, 140,   0,   0,  17, 
    146,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
     23,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     23,   0,   0,   0,   2,  64, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,   6,  12,  16,   0, 
      2,   0,   0,   0,  35,   0, 
      0,  12,  82,   0,  16,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   6,   3,  16,   0, 
      2,   0,   0,   0, 140,   0, 
      0,  11,  18,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  12,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
      1,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   7,   0,   0,  30,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,   1,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
     30,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  11,  34,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   6,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0, 140,   0, 
      0,  11, 130,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     21,   0,   0,   1,  18,   0, 
      0,   1,  35,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,   2,   0, 
     58, 128,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  26,   0, 
      2,   0,  35,   0,   0,  11, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  42, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  30,   0,   0,   9, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  85,   0,   0,  10, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   4,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    138,   0,   0,  11, 130,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  10, 128, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  45,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  32,   0, 
      0,  10, 114,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  60,   0,   0,   7, 
     50,   0,  16,   0,   2,   0, 
      0,   0, 150,   5,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     41,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,  85,   0,   0,  10, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,   2,  64,   0,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0,  30,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  21,   0,   0,   1, 
     31,   0,   4,   3,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     85,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0, 140,   0, 
      0,  17, 242,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,  64,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     21,   0,   0,   1, 139,   0, 
      0,  15, 242,   0,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  43,   0, 
      0,   5, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   1,   0,  56,   0,   1, 
      0,  56,   0,   1,   0,  56, 
      0,   1,   0,  56,  52,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
    128, 191,  42,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     43,   0,   0,   5, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   1,   0,  56, 
      0,   1,   0,  56,   0,   1, 
      0,  56,   0,   1,   0,  56, 
     52,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0, 128, 191, 130,   0, 
      0,   5, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
    130,   0,   0,   5, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  35,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0, 164,   0,   0,   8, 
    242, 224,  33,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  30,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  31,   0,   4,   3, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
     32,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   5, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
     16,   0,   0,   0,  21,   0, 
      0,   1,  85,   0,   0,   7, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   4,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  45,   0, 
      0,   8, 242,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     41,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,   0, 255,   0, 255, 
      0, 255,  85,   0,   0,  10, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,   2,  64,   0,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0, 255,   0, 
    255,   0, 255,   0,  30,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  21,   0,   0,   1, 
     31,   0,   4,   3,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     85,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0, 140,   0, 
      0,  17, 242,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,  64,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     21,   0,   0,   1, 139,   0, 
      0,  15, 242,   0,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  43,   0, 
      0,   5, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   1,   0,  56,   0,   1, 
      0,  56,   0,   1,   0,  56, 
      0,   1,   0,  56,  52,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
    128, 191,  42,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
     43,   0,   0,   5, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   1,   0,  56, 
      0,   1,   0,  56,   0,   1, 
      0,  56,   0,   1,   0,  56, 
     52,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0, 128, 191, 130,   0, 
      0,   5, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
    130,   0,   0,   5, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  35,   0,   0,  12, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0, 164,   0,   0,   8, 
    242, 224,  33,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0, 128,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     38,   0,   0,   0,  22,   0, 
      0,   0,   5,   0,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0
};
