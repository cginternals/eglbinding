ARG BASE=cginternals/cpp-base:dev
ARG GRAPHICS_DRIVER=nvidia-driver-470
ARG PROJECT_NAME=eglbinding
ARG CPPLOCATE_DEPENDENCY=cginternals/cpplocate:latest
ARG GLBINDING_DEPENDENCY=cginternals/glbinding:latest
ARG GLESBINDING_DEPENDENCY=cginternals/glesbinding:latest

# DEPENDENCIES

FROM $CPPLOCATE_DEPENDENCY AS cpplocate

FROM $GLBINDING_DEPENDENCY AS glbinding

FROM $GLESBINDING_DEPENDENCY AS glesbinding

# BUILD

FROM $BASE as build

ARG PROJECT_NAME
ARG COMPILER_FLAGS="-j 4"
ARG GRAPHICS_DRIVER

RUN apt install -y --no-install-recommends $GRAPHICS_DRIVER
RUN apt install -y --no-install-recommends libegl-dev

COPY --from=cpplocate $WORKSPACE/cpplocate $WORKSPACE/cpplocate
COPY --from=glbinding $WORKSPACE/glbinding $WORKSPACE/glbinding
COPY --from=glesbinding $WORKSPACE/glesbinding $WORKSPACE/glesbinding

ENV glbinding_DIR="$WORKSPACE/glbinding"
ENV glesbinding_DIR="$WORKSPACE/glesbinding"

WORKDIR $WORKSPACE/$PROJECT_NAME

ADD cmake cmake
ADD data data
ADD deploy deploy
ADD docs docs
ADD source source
ADD CMakeLists.txt CMakeLists.txt
ADD configure configure
ADD $PROJECT_NAME-config.cmake $PROJECT_NAME-config.cmake
ADD LICENSE LICENSE
ADD README.md README.md
ADD AUTHORS AUTHORS

RUN ./configure
RUN CMAKE_OPTIONS="-DOPTION_BUILD_TESTS=Off" ./configure
RUN cmake --build build -- $COMPILER_FLAGS

# INSTALL

FROM build as install

ARG PROJECT_NAME

WORKDIR $WORKSPACE/$PROJECT_NAME

RUN CMAKE_OPTIONS="-DCMAKE_INSTALL_PREFIX=$WORKSPACE/$PROJECT_NAME-install" ./configure
RUN cmake --build build --target install

# DEPLOY

FROM $BASE AS deploy

ARG PROJECT_NAME

COPY --from=build $WORKSPACE/cpplocate $WORKSPACE/cpplocate
COPY --from=build $WORKSPACE/glbinding $WORKSPACE/glbinding
COPY --from=build $WORKSPACE/glesbinding $WORKSPACE/glesbinding

COPY --from=install $WORKSPACE/$PROJECT_NAME-install $WORKSPACE/$PROJECT_NAME

ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORKSPACE/cpplocate/lib
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORKSPACE/glbinding/lib
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORKSPACE/glesbinding/lib
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORKSPACE/$PROJECT_NAME/lib
