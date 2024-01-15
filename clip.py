from PIL import Image
import requests
import glob
from transformers import CLIPProcessor, CLIPModel

model = CLIPModel.from_pretrained("openai/clip-vit-base-patch32")
# model = CLIPModel.from_pretrained("./clip-vit-base-patch32/")
processor = CLIPProcessor.from_pretrained("openai/clip-vit-base-patch32")
#  processor = CLIPProcessor.from_pretrained("./clip-vit-base-patch32/")

# img_path = "testing.jpeg"
# image = Image.open(img_path)
# Get a list of file paths
img_paths = glob.glob("images/*")
image = []
for img_path in img_paths:
    print(img_path)
    image.append(Image.open(img_path))
text = ["sleeping"]
inputs = processor(text=text, images=image, return_tensors="pt", padding=True)

outputs = model(**inputs)
# logits_per_image = outputs.logits_per_image  # this is the image-text similarity score
# print(logits_per_image )
# probs = logits_per_image.softmax(dim=1)  # we can take the softmax to get the label probabilities
logits_per_text = outputs.logits_per_text
probs = logits_per_text.softmax(dim=1)
print(probs)
print("the command of {} is mostly likely to be {}".format(text,probs.argmax(dim=1)))
# print(probs)
# print("The image is most likely a {}".format(text[probs.argmax(dim=1)]))
