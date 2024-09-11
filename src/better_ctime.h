#ifndef __INCLUDE_RS_SYSTEMTIME_H
#define __INCLUDE_RS_SYSTEMTIME_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Duration Duration;

typedef struct SystemTime SystemTime;

uint64_t duration_as_micros(const struct Duration* self);

uint64_t duration_as_millis(const struct Duration* self);

uint64_t duration_as_nanos(const struct Duration* self);

uint64_t duration_as_secs(const struct Duration* self);

float duration_as_secs_f32(const struct Duration* self);

double duration_as_secs_f64(const struct Duration* self);

uint32_t duration_subsec_micros(const struct Duration* self);

uint32_t duration_subsec_millis(const struct Duration* self);

uint32_t duration_subsec_nanos(const struct Duration* self);

struct Duration* duration_div_f32(const struct Duration* self, float rhs);

struct Duration* duration_div_f64(const struct Duration* self, double rhs);

struct Duration* duration_mul_f32(const struct Duration* self, float rhs);

struct Duration* duration_mul_f64(const struct Duration* self, double rhs);

struct Duration* duration_saturating_add(const struct Duration* self,
                                         struct Duration* dur);

struct Duration* duration_saturating_sub(const struct Duration* self,
                                         struct Duration* dur);

struct Duration* duration_saturating_mul(const struct Duration* self,
                                         uint32_t dur);

struct Duration* duration_checked_add(const struct Duration* self,
                                      struct Duration* dur);

struct Duration* duration_checked_sub(const struct Duration* self,
                                      struct Duration* dur);

struct Duration* duration_checked_mul(const struct Duration* self,
                                      uint32_t dur);

struct SystemTime* new_system_time(void);

struct SystemTime* system_time_get_epoch(void);

struct Duration* system_time_get_duration(const struct SystemTime* self);

#endif /* __INCLUDE_RS_SYSTEMTIME_H */
