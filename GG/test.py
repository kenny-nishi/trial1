# import all the modules that we will need to use
from TTS.utils.manage import ModelManager
from TTS.utils.synthesizer import Synthesizer

# path = "/Users/mm/Desktop/CE4_Sem1/FYP/ultralytics/.venv/lib/python3.11/site-packages/TTS/.models.json"
path = "/Users/mm/Desktop/CE4_Sem1/FYP/ultralytics/TTS/TTS/MM/tmp/xtts_ft/dataset/config.json"

model_manager = ModelManager(path)

model_path, config_path, model_item = model_manager.download_model("tts_models/en/ljspeech/tacotron2-DDC")

voc_path, voc_config_path, _ = model_manager.download_model(model_item["default_vocoder"])

syn = Synthesizer(      
    tts_checkpoint=model_path,
    tts_config_path=config_path,
    vocoder_checkpoint=voc_path,
    vocoder_config=voc_config_path
)

text = "Hello World"

outputs = syn.tts(text)
syn.save_wav(outputs, "audio-1.wav")