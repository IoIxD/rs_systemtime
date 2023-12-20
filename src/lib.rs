use std::ptr::null_mut;

pub struct Duration {
    dur: std::time::Duration,
}

impl Duration {
    fn from(dur: std::time::Duration) -> &'static mut Self {
        return Box::leak(Box::new(Self { dur }));
    }

    #[no_mangle]
    pub extern "C" fn duration_as_micros(&self) -> u64 {
        return self.dur.as_micros() as u64;
    }

    #[no_mangle]
    pub extern "C" fn duration_as_millis(&self) -> u64 {
        return self.dur.as_millis() as u64;
    }

    #[no_mangle]
    pub extern "C" fn duration_as_nanos(&self) -> u64 {
        return self.dur.as_nanos() as u64;
    }

    #[no_mangle]
    pub extern "C" fn duration_as_secs(&self) -> u64 {
        return self.dur.as_secs();
    }

    #[no_mangle]
    pub extern "C" fn duration_as_secs_f32(&self) -> f32 {
        return self.dur.as_secs_f32();
    }

    #[no_mangle]
    pub extern "C" fn duration_as_secs_f64(&self) -> f64 {
        return self.dur.as_secs_f64();
    }

    #[no_mangle]
    pub extern "C" fn duration_subsec_micros(&self) -> u32 {
        return self.dur.subsec_micros();
    }

    #[no_mangle]
    pub extern "C" fn duration_subsec_millis(&self) -> u32 {
        return self.dur.subsec_millis();
    }

    #[no_mangle]
    pub extern "C" fn duration_subsec_nanos(&self) -> u32 {
        return self.dur.subsec_nanos();
    }

    #[no_mangle]
    pub extern "C" fn duration_div_f32(&self, rhs: f32) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.div_f32(rhs),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_div_f64(&self, rhs: f64) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.div_f64(rhs),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_mul_f32(&self, rhs: f32) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.mul_f32(rhs),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_mul_f64(&self, rhs: f64) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.mul_f64(rhs),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_saturating_add(&self, dur: &'static mut Self) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.saturating_add(dur.dur),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_saturating_sub(&self, dur: &'static mut Self) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.saturating_sub(dur.dur),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_saturating_mul(&self, dur: u32) -> &'static mut Self {
        Box::leak(Box::new(Self {
            dur: self.dur.saturating_mul(dur),
        }))
    }

    #[no_mangle]
    pub extern "C" fn duration_checked_add(&self, dur: &'static mut Self) -> *mut Self {
        match self.dur.checked_add(dur.dur) {
            Some(a) => Box::leak(Box::new(Self { dur: a })),
            None => null_mut(),
        }
    }
    #[no_mangle]
    pub extern "C" fn duration_checked_sub(&self, dur: &'static mut Self) -> *mut Self {
        match self.dur.checked_sub(dur.dur) {
            Some(a) => Box::leak(Box::new(Self { dur: a })),
            None => null_mut(),
        }
    }
    #[no_mangle]
    pub extern "C" fn duration_checked_mul(&self, dur: u32) -> *mut Self {
        match self.dur.checked_mul(dur) {
            Some(a) => Box::leak(Box::new(Self { dur: a })),
            None => null_mut(),
        }
    }
}

pub struct SystemTime {
    time: std::time::SystemTime,
}

impl SystemTime {
    #[no_mangle]
    pub extern "C" fn new_system_time() -> &'static mut Self {
        return Box::leak(Box::new(Self {
            time: std::time::SystemTime::now(),
        }));
    }
    #[no_mangle]
    pub extern "C" fn system_time_get_epoch() -> &'static mut Self {
        return Box::leak(Box::new(Self {
            time: std::time::SystemTime::UNIX_EPOCH,
        }));
    }
    #[no_mangle]
    pub extern "C" fn system_time_get_duration(&self) -> &'static mut Duration {
        return Duration::from(self.time.elapsed().unwrap());
    }
}
