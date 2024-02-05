# pip install tts
# to locate the path of the tts, press type the following line: pip show tts


# import all the modules that we will need to use
from TTS.utils.manage import ModelManager
from TTS.utils.synthesizer import Synthesizer

# path = "/Users/mm/Desktop/CE4_Sem1/FYP/ultralytics/.venv/lib/python3.11/site-packages/TTS/.models.json"
path = "/home/fai/.local/lib/python3.8/site-packages/TTS/.models.json"

model_manager = ModelManager(path)

model_path, config_path, model_item = model_manager.download_model("tts_models/en/ljspeech/tacotron2-DDC")

voc_path, voc_config_path, _ = model_manager.download_model(model_item["default_vocoder"])

syn = Synthesizer(
    tts_checkpoint=model_path,
    tts_config_path=config_path,
    vocoder_checkpoint=voc_path,
    vocoder_config=voc_config_path
)

text = "More than 500 people have been evacuated from a village in southwestern China as rescue workers scrabble to reach 47 of their neighbours who were buried under a landslide early on Monday morning. State broadcaster CCTV reported that 18 homes were in the path of the landslide which struck the village of Liangshui in Zhenxiong county, Yunnan province, at 5.51am. CCTV has updated an earlier report to confirm that there are more than 300 rescue personnel and over 50 emergency units, including fire trucks and loaders, working in the freezing conditions to locate the missing"

outputs = syn.tts(text)
syn.save_wav(outputs, "audio-1.wav")
