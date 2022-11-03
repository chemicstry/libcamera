#pragma once

#include <libcamera/c_api/camera.h>

#ifdef __cplusplus
extern "C" {
#endif

// libcamera::CameraManager*
typedef struct __libcamera_camera_manager_t* libcamera_camera_manager_t;

// std::vector<shared_ptr<libcamera::Camera>>
typedef struct __libcamera_camera_list_t* libcamera_camera_list_t;

// --- libcamera_camera_manager_t ---

libcamera_camera_manager_t libcamera_camera_manager_create();
void libcamera_camera_manager_destroy(libcamera_camera_manager_t mgr);

int libcamera_camera_manager_start(libcamera_camera_manager_t mgr);
void libcamera_camera_manager_stop(libcamera_camera_manager_t mgr);

libcamera_camera_list_t libcamera_camera_manager_cameras(libcamera_camera_manager_t mgr);

// --- libcamera_camera_list_t ---

void libcamera_camera_list_destroy(libcamera_camera_list_t list);

int libcamera_camera_list_size(libcamera_camera_list_t list);
libcamera_camera_t libcamera_camera_list_get(libcamera_camera_list_t list, int index);

#ifdef __cplusplus
}
#endif
