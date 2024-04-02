# best model, training file in binchilin: training_best folder
import os
import torch
import torchaudio
from TTS.tts.configs.xtts_config import XttsConfig
from TTS.tts.models.xtts import Xtts

# Add here the xtts_config path
CONFIG_PATH = r"C:\Users\MM\Desktop\xtts\config.json"
# Add here the vocab file that you have used to train the model
TOKENIZER_PATH = r"C:\Users\MM\Desktop\xtts\vocab.json"
# Add here the checkpoint that you want to do inference with
XTTS_CHECKPOINT = r"C:\Users\MM\Desktop\xtts\model.pth"
# Add here the speaker reference
SPEAKER_REFERENCE_SURPRISE = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\surpise_1_00000000.wav"
SPEAKER_REFERENCE_NORMAL = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\emails_00000002.wav"
SPEAKER_REFERENCE_SAD = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\Sad_1_00000000.wav"
SPEAKER_REFERENCE_HAPI = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\hapi_1_00000000.wav"
SPEAKER_REFERENCE_ANGER = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\anger_2_00000000.wav"
SPEAKER_REFERENCE_FEAR = r"C:\Users\MM\Desktop\xtts\dataset\tmp\xtts_ft\dataset\wavs\fear_1_00000000.wav"

# output wav path
OUTPUT_WAV_PATH = r"C:\Users\MM\Desktop\xtts\xtts-ft.wav"

print("Loading model...")
global XTTS_MODEL
config = XttsConfig()
config.load_json(CONFIG_PATH)
XTTS_MODEL = Xtts.init_from_config(config)
print("Loading XTTS model! ")
XTTS_MODEL.load_checkpoint(config, checkpoint_path=XTTS_CHECKPOINT, vocab_path=TOKENIZER_PATH, use_deepspeed=False)
if torch.cuda.is_available():
    XTTS_MODEL.cuda()

    print("Model Loaded!")
while(1):
    lan = input("Language(English (en), Spanish (es), French (fr), German (de), Italian (it), Portuguese (pt), Polish (pl), Turkish (tr), Russian (ru), Dutch (nl), Czech (cs), Arabic (ar), Chinese (zh-cn), Japanese (ja), Hungarian (hu) and Korean (ko)): ")
    textts = input("Text: ")
    REFERENCE = input("Tone ([s]urprise, [n]ormal, [sa]d, [h]appy, [a]nger, [f]ear):")
    if REFERENCE == "s":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_SURPRISE
    elif REFERENCE == "n":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_NORMAL
    elif REFERENCE == "sa":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_SAD
    elif REFERENCE == "h":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_HAPI
    elif REFERENCE == "a":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_ANGER
    elif REFERENCE == "f":
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_FEAR
    else:
        SPEAKER_REFERENCE = SPEAKER_REFERENCE_NORMAL
    
    gpt_cond_latent, speaker_embedding = XTTS_MODEL.get_conditioning_latents(audio_path=SPEAKER_REFERENCE, gpt_cond_len=XTTS_MODEL.config.gpt_cond_len, max_ref_length=XTTS_MODEL.config.max_ref_len, sound_norm_refs=XTTS_MODEL.config.sound_norm_refs)
    out = XTTS_MODEL.inference(
        text=textts,
        language=lan,
        gpt_cond_latent=gpt_cond_latent,
        speaker_embedding=speaker_embedding,
        temperature=XTTS_MODEL.config.temperature, # Add custom parameters here
        length_penalty=XTTS_MODEL.config.length_penalty,
        repetition_penalty=XTTS_MODEL.config.repetition_penalty,
        top_k=XTTS_MODEL.config.top_k,
        top_p=XTTS_MODEL.config.top_p,
    )
    torchaudio.save(OUTPUT_WAV_PATH, torch.tensor(out["wav"]).unsqueeze(0), 24000)
