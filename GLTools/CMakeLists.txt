set(HEADER_PATH ./include)

set(HEADER_FILES
  ${HEADER_PATH}/GLBatch.h
  ${HEADER_PATH}/GLBatchBase.h
  ${HEADER_PATH}/GLFrame.h
  ${HEADER_PATH}/GLFrustum.h
  ${HEADER_PATH}/GLGeometryTransform.h
  ${HEADER_PATH}/GLMatrixStack.h
  ${HEADER_PATH}/GLShaderManager.h
  ${HEADER_PATH}/GLTools.h
  ${HEADER_PATH}/GLTriangleBatch.h
  ${HEADER_PATH}/math3d.h
  ${HEADER_PATH}/StopWatch.h
  ${HEADER_PATH}/glad.h
  )

set(SOURCE_PATH ./src)
set(SOURCE_FILES
  ${SOURCE_PATH}/GLBatch.cpp
  ${SOURCE_PATH}/GLShaderManager.cpp
  ${SOURCE_PATH}/GLTools.cpp
  ${SOURCE_PATH}/GLTriangleBatch.cpp
  ${SOURCE_PATH}/math3d.cpp
  ${SOURCE_PATH}/glad.c
  )

add_library(gltools
  ${HEADER_FILES}
  ${SOURCE_FILES}
  )

target_include_directories(gltools PUBLIC ${HEADER_PATH})
link_directories(${LIBRARY_OUTPUT_DIRECTORY})
