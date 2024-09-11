use std::env;

use cbindgen::{Config, Language};

fn main() {
    let crate_dir = env::var("CARGO_MANIFEST_DIR").unwrap();

    let output_file = "include/rs_systemtime.h";

    let mut config = Config::default();
    config.namespace = None;
    config.language = Language::C;
    config.include_guard = Some("__INCLUDE_RS_SYSTEMTIME_H".to_string());

    cbindgen::generate_with_config(&crate_dir, config)
        .unwrap()
        .write_to_file(&output_file);
    println!("cargo:rerun-if-changed=src/lib.rs");
}
