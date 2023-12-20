TARGET = prog

PREFIX=""

ifeq ($(OS),Windows_NT)
	PREFIX = .dll
else
	PREFIX = .a
endif

$(TARGET): target/release/libbetter_ctime$(PREFIX)

target/release/libbetter_ctime.a:
	cargo build --release
	mv target/release/libbetter_ctime.a .

target/release/libbetter_ctime.dll:
	cargo build --release --target=x86_64-pc-windows-gnu
	mv target/release/libbetter_ctime.dll .

clean:
	cargo clean
