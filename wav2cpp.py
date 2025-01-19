import argparse
from scipy.io import wavfile
import numpy as np

def convertWavToCpp(inputFile, outputName):
    sampleRate, data = wavfile.read(inputFile)

    # 8ビットPCMに変換
    data = ((data / np.max(np.abs(data))) * 127 + 128).astype(np.uint8)

    # cppの配列形式に変換
    with open(outputName + ".h", "w") as f:
        f.write("#ifndef " + outputName.upper() + "_H\n")
        f.write("#define " + outputName.upper() + "_H\n")
        f.write("extern const uint8_t " + outputName + "[] = {\n")
        if data.ndim == 1:
            f.write(",".join(map(str, data)))
        else:
            f.write(",".join(map(str, [item[0] for item in data])))
        f.write("\n};\n")
        f.write("#endif")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="WAVファイルをC++の配列形式に変換")
    parser.add_argument("inputFile", help="入力WAVファイル")
    parser.add_argument("outputName", help="出力C++ヘッダーファイル・関数名")
    
    args = parser.parse_args()
    
    # WAVファイルをC++形式に変換
    convertWavToCpp(args.inputFile, args.outputName)