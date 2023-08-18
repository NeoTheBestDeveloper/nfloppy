clean:
	rm -rf build 
	rm -rf .cache 
	rm -rf build_release

setup:
	# meson setup -Db_sanitize=address,undefined --wipe build
	meson setup --wipe build

dev:
	meson compile -j 8 -C build

release:
	meson setup --buildtype=release --wipe build_release
	meson compile -j 8 -C build_release
	strip build_release/nfloppy
