import idx2numpy

labels_file = "t10k-labels.idx1-ubyte"
images_file = "t10k-images.idx3-ubyte"

labels_data = idx2numpy.convert_from_file(labels_file)
images_data = idx2numpy.convert_from_file(images_file)

# Display number of instances:
n_images, im_size = images_data.shape[:2]
n_labels = labels_data.shape[0]
print(f"There is {n_images} images.")
print(f"There is {n_labels} labels.")
print(f"The images size is {im_size}.")
