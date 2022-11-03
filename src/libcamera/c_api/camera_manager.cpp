#include "libcamera/c_api/camera_manager.h"
#include "libcamera/camera_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

struct __libcamera_camera_manager_t {
    std::unique_ptr<libcamera::CameraManager> instance;
};

struct __libcamera_camera_list_t {
    std::vector<std::shared_ptr<libcamera::Camera>> instance;
};

libcamera_camera_manager_t libcamera_camera_manager_create() {
    return new __libcamera_camera_manager_t { std::make_unique<libcamera::CameraManager>() };
}

void libcamera_camera_manager_destroy(libcamera_camera_manager_t mgr) {
    delete mgr;
}

int libcamera_camera_manager_start(libcamera_camera_manager_t mgr) {
    return mgr->instance->start();
}

void libcamera_camera_manager_stop(libcamera_camera_manager_t mgr) {
    mgr->instance->stop();
}

libcamera_camera_list_t libcamera_camera_manager_cameras(libcamera_camera_manager_t mgr) {
    auto cameras = mgr->instance->cameras();
    return new __libcamera_camera_list_t { cameras };
}

int libcamera_camera_list_size(libcamera_camera_list_t list) {
    return list->instance.size();
}

libcamera_camera_t libcamera_camera_list_get(libcamera_camera_list_t list, int index) {
    if (list->instance.size() <= index) {
        return nullptr;
    } else {
        return new __libcamera_camera_t { list->instance[index] }
    }
}

void libcamera_camera_list_destroy(libcamera_camera_list_t list) {
    delete reinterpret_cast<std::vector<std::shared_ptr<libcamera::Camera>>*>(list);
}

#ifdef __cplusplus
}
#endif
