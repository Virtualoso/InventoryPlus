#pragma once

#include <string>

class ImagePickingCallback {

public:
    virtual ~ImagePickingCallback() { }
    virtual void onImagePickingSuccess(const std::string&) = 0;
    virtual void onImagePickingCanceled() = 0;

};
