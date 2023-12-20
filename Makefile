TARGET = prog

$(TARGET): target/release/libbetter_ctime.a
	
target/release/libbetter_ctime.a:
	cargo build --release
	mv target/release/libbetter_ctime.a .

clean:
	cargo clean