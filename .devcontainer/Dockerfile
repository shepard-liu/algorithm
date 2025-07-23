FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.22.2"

# Optionally install the cmake for vcpkg
COPY . /_tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /_tmp/reinstall-cmake.sh && /_tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi


# install dependencies
RUN chmod +x /_tmp/install_deps.sh && /bin/bash -c /_tmp/install_deps.sh

RUN rm -rf /_tmp/