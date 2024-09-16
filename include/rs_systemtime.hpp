#ifndef __RS_SYSTEMTIME_HPP
#define __RS_SYSTEMTIME_HPP

#include <cstdint>
#include <cstdlib>
namespace internal {
extern "C" {
#include "rs_systemtime.h"
}
}  // namespace internal

class Duration {
 private:
  internal::Duration* inner;
  Duration(internal::Duration* dur) { this->inner = dur; };
  ~Duration() { free(this->inner); };

 public:
  uint64_t as_micros() { return internal::duration_as_micros(this->inner); };

  uint64_t as_millis() { return internal::duration_as_millis(this->inner); };

  uint64_t as_nanos() { return internal::duration_as_nanos(this->inner); };

  uint64_t as_secs() { return internal::duration_as_secs(this->inner); };

  float as_secs_f32() { return internal::duration_as_secs_f32(this->inner); };

  double as_secs_f64() { return internal::duration_as_secs_f64(this->inner); };

  uint32_t subsec_micros() {
    return internal::duration_subsec_micros(this->inner);
  };

  uint32_t subsec_millis() {
    return internal::duration_subsec_millis(this->inner);
  };

  uint32_t subsec_nanos() {
    return internal::duration_subsec_nanos(this->inner);
  };

  Duration* div_f32(float rhs) {
    return new Duration(internal::duration_div_f32(this->inner, rhs));
  };

  Duration* div_f64(double rhs) {
    return new Duration(internal::duration_div_f64(this->inner, rhs));
  };

  Duration* mul_f32(float rhs) {
    return new Duration(internal::duration_mul_f32(this->inner, rhs));
  };

  Duration* mul_f64(double rhs) {
    return new Duration(internal::duration_mul_f64(this->inner, rhs));
  };

  Duration* saturating_add(Duration* rhs) {
    return new Duration(
        internal::duration_saturating_add(this->inner, rhs->inner));
  };

  Duration* saturating_sub(Duration* rhs) {
    return new Duration(
        internal::duration_saturating_sub(this->inner, rhs->inner));
  };

  Duration* saturating_mul(uint32_t rhs) {
    return new Duration(internal::duration_saturating_mul(this->inner, rhs));
  };

  Duration* checked_add(Duration* rhs) {
    return new Duration(
        internal::duration_checked_add(this->inner, rhs->inner));
  };

  Duration* checked_sub(Duration* rhs) {
    return new Duration(
        internal::duration_checked_sub(this->inner, rhs->inner));
  };

  Duration* checked_mul(uint32_t rhs) {
    return new Duration(internal::duration_checked_mul(this->inner, rhs));
  };

  Duration* operator+(Duration& rhs) {
    return this->saturating_add(&rhs);
  };

  Duration* operator-(Duration& rhs) {
    return this->saturating_sub(&rhs);
  };
  Duration* operator*(uint32_t rhs) {
    return this->saturating_mul(rhs);
  };
  Duration* operator*(float rhs) {
    return this->mul_f32(rhs);
  };
  Duration* operator*(double rhs) {
    return this->mul_f64(rhs);
  };

  Duration* operator/(float rhs) {
    return this->div_f32(rhs);
  };
  Duration* operator/(double rhs) {
    return this->div_f64(rhs);
  };
  friend class SystemTime;
};

class SystemTime {
  internal::SystemTime* inner;
  SystemTime(internal::SystemTime* t) { this->inner = t; }

 public:
  SystemTime() { this->inner = internal::new_system_time(); }
  ~SystemTime() { free(this->inner); };

  static SystemTime get_epoch() {
    return SystemTime(internal::system_time_get_epoch());
  }

  Duration* get_duration() {
    return new Duration(internal::system_time_get_duration(this->inner));
  };
};

/* uint64_t as_micros();

uint64_t as_millis();

uint64_t as_nanos();

uint64_t as_secs();

float as_secs_f32();

double as_secs_f64();

uint32_t subsec_micros();

uint32_t subsec_millis();

uint32_t subsec_nanos();

struct Duration *div_f32(float rhs);

struct Duration *div_f64(double rhs);

struct Duration *mul_f32(float rhs);

struct Duration *mul_f64(double rhs);

struct Duration *saturating_add(struct
Duration *dur);

struct Duration *saturating_sub(struct
Duration *dur);

struct Duration *saturating_mul(uint32_t
dur);

struct Duration *checked_add(struct
Duration *dur);

struct Duration *checked_sub(struct
Duration *dur);

struct Duration *checked_mul(uint32_t
dur);

struct Duration *system_time_get_duration();*/

#endif
