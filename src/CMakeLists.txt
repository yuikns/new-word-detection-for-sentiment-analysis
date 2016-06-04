ADD_EXECUTABLE(nwd4sa nwd4sa.cc)

ADD_DEPENDENCIES(nwd4sa argcv)

TARGET_LINK_LIBRARIES(nwd4sa argcv_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_ir_index_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_string_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_sys_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_wrapper_leveldb_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_wrapper_ini_static)
TARGET_LINK_LIBRARIES(nwd4sa argcv_storage_static)

TARGET_LINK_LIBRARIES(nwd4sa pthread)

TARGET_LINK_LIBRARIES(nwd4sa ${CRFPP_LIBRARY_STATIC})
TARGET_LINK_LIBRARIES(nwd4sa ${LEVELDB_LIBRARY_STATIC})
TARGET_LINK_LIBRARIES(nwd4sa ${MONGO_CXX_LIBRARY_STATIC})

SET_TARGET_PROPERTIES(nwd4sa PROPERTIES OUTPUT_NAME "nwd4sa")


########################################################################################



