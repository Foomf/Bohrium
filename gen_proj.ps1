New-Item -ItemType Directory -Force -Path build

cmake `
    -G "MSYS Makefiles" `
    -B build `
    -DCMAKE_BUILD_TYPE=Debug `
    -DBOHRIUM_SERVER_EXECUTABLE=ON `
    -DCMAKE_DISABLE_TESTING=ON `
    -DZF_LOG_CONFIGURE_INSTALL=OFF
