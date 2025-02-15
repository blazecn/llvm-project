// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1  -triple aarch64-none-linux-gnu -target-feature +sve \
// RUN:   -target-feature +sme -target-feature +sve2 -target-feature +neon -fsyntax-only -verify %s

// REQUIRES: aarch64-registered-target

#include "arm_neon.h"
#include "arm_sme_draft_spec_subject_to_change.h"
#include "arm_sve.h"

int16x8_t incompat_neon_sm(int16x8_t splat) __arm_streaming {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return (int16x8_t)__builtin_neon_vqaddq_v((int8x16_t)splat, (int8x16_t)splat, 33);
}

__arm_locally_streaming int16x8_t incompat_neon_ls(int16x8_t splat) {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return (int16x8_t)__builtin_neon_vqaddq_v((int8x16_t)splat, (int8x16_t)splat, 33);
}

int16x8_t incompat_neon_smc(int16x8_t splat) __arm_streaming_compatible {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming compatible function}}
  return (int16x8_t)__builtin_neon_vqaddq_v((int8x16_t)splat, (int8x16_t)splat, 33);
}

void incompat_sme_smc(svbool_t pg, void const *ptr) __arm_streaming_compatible __arm_shared_za {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming compatible function}}
  return __builtin_sme_svld1_hor_za128(0, 0, pg, ptr);
}

svuint32_t incompat_sve_sm(svbool_t pg, svuint32_t a, int16_t b) __arm_streaming {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return __builtin_sve_svld1_gather_u32base_index_u32(pg, a, b);
}

__arm_locally_streaming svuint32_t incompat_sve_ls(svbool_t pg, svuint32_t a, int64_t b) {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return __builtin_sve_svld1_gather_u32base_index_u32(pg, a, b);
}

svuint32_t incompat_sve_smc(svbool_t pg, svuint32_t a, int64_t b) __arm_streaming_compatible {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming compatible function}}
  return __builtin_sve_svld1_gather_u32base_index_u32(pg, a, b);
}

svuint32_t incompat_sve2_sm(svbool_t pg, svuint32_t a, int64_t b) __arm_streaming {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return __builtin_sve_svldnt1_gather_u32base_index_u32(pg, a, b);
}

__arm_locally_streaming svuint32_t incompat_sve2_ls(svbool_t pg, svuint32_t a, int64_t b) {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming function}}
  return __builtin_sve_svldnt1_gather_u32base_index_u32(pg, a, b);
}

svuint32_t incompat_sve2_smc(svbool_t pg, svuint32_t a, int64_t b) __arm_streaming_compatible {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a streaming compatible function}}
  return __builtin_sve_svldnt1_gather_u32base_index_u32(pg, a, b);
}

void incompat_sme_sm(svbool_t pn, svbool_t pm, svfloat32_t zn, svfloat32_t zm) __arm_shared_za {
  // expected-warning@+1 {{builtin call has undefined behaviour when called from a non-streaming function}}
  svmops_za32_f32_m(0, pn, pm, zn, zm);
}

svfloat64_t streaming_caller_sve(svbool_t pg, svfloat64_t a, float64_t b) __arm_streaming {
  // expected-no-warning
  return svadd_n_f64_m(pg, a, b);
}

__arm_locally_streaming svfloat64_t locally_streaming_caller_sve(svbool_t pg, svfloat64_t a, float64_t b) {
  // expected-no-warning
  return svadd_n_f64_m(pg, a, b);
}

svfloat64_t streaming_compatible_caller_sve(svbool_t pg, svfloat64_t a, float64_t b) __arm_streaming_compatible {
  // expected-no-warning
  return svadd_n_f64_m(pg, a, b);
}

svint16_t streaming_caller_sve2(svint16_t op1, svint16_t op2) __arm_streaming {
  // expected-no-warning
  return svmul_lane_s16(op1, op2, 0);
}

__arm_locally_streaming svint16_t locally_streaming_caller_sve2(svint16_t op1, svint16_t op2) {
  // expected-no-warning
  return svmul_lane_s16(op1, op2, 0);
}

svint16_t streaming_compatible_caller_sve2(svint16_t op1, svint16_t op2) __arm_streaming_compatible {
  // expected-no-warning
  return svmul_lane_s16(op1, op2, 0);
}

svbool_t streaming_caller_ptrue(void) __arm_streaming {
  // expected-no-warning
  return svand_z(svptrue_b16(), svptrue_pat_b16(SV_ALL), svptrue_pat_b16(SV_VL4));
}
