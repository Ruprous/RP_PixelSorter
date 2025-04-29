#include "AEConfig.h"
#include "AEGP.h"
#include "Entry.h"
#include "AEGP_SuiteHandler.h"

// 設定する必要のある定数
#define PLUGIN_NAME "RP_PixelSorter"
#define PLUGIN_VERSION "1.0"

// ピクセルソートの関数
void PixelSort(
    AEGP_FrameFormat frameFormat,
    AEGP_PictureH inputPicture,
    AEGP_PictureH outputPicture,
    float xStrength,
    float yStrength,
    float referenceBrightness,
    float brightnessRange,
    float pixelWidth
) {
    // ここにピクセルソートの処理を書く
    // inputPictureを処理してoutputPictureに結果を保存する
}

// エフェクトの実装
static A_Err 
EffectMain(
    AEGP_CompH compH,
    AEGP_EffectH effectH,
    AEGP_PictureH inputPicture,
    AEGP_PictureH outputPicture
) {
    A_Err err = A_Err_NONE;

    // プラグインの設定を取得
    float xStrength = 0.0f; // ここにUIから取得した値をセットする
    float yStrength = 0.0f; // ここにUIから取得した値をセットする
    float referenceBrightness = 0.5f; // UIから取得
    float brightnessRange = 0.5f; // UIから取得
    float pixelWidth = 1.0f; // UIから取得

    // ピクセルソート処理を呼び出す
    PixelSort(compH->frameFormat, inputPicture, outputPicture, xStrength, yStrength, referenceBrightness, brightnessRange, pixelWidth);

    return err;
}

// プラグインのエントリーポイント
extern "C" 
{
    DllExport A_Err 
    PluginInit(AEGP_PluginID pluginID)
    {
        A_Err err = A_Err_NONE;
        // エフェクトを登録する処理を書く

        return err;
    }

    DllExport A_Err 
    PluginExit(AEGP_PluginID pluginID)
    {
        A_Err err = A_Err_NONE;
        // プラグインの終了処理を書く

        return err;
    }
}
