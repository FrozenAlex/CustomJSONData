#include "CustomBeatmapSaveDatav3.h"
#include "CustomBeatmapSaveDatav2.h"
#include "BeatmapFieldUtils.hpp"

#include "VList.h"

#include "GlobalNamespace/BeatmapEventTypeExtensions.hpp"
#include "GlobalNamespace/IndexFilter.hpp"
#include "GlobalNamespace/BeatmapDataSortedListForTypeAndIds_1.hpp"
#include "GlobalNamespace/LightTranslationBeatmapEventDataBox.hpp"

#include "BeatmapSaveDataVersion2_6_0AndEarlier/BeatmapSaveData_SpecialEventsForKeyword.hpp"

#include "cpp-semver/shared/cpp-semver.hpp"
#include "GlobalNamespace/NoteLineLayer.hpp"
#include "GlobalNamespace/EaseType.hpp"

#include <numeric>

using namespace GlobalNamespace;
using namespace BeatmapSaveDataVersion3;
using namespace CustomJSONData::v3;

UnorderedEventCallback<CustomJSONData::v3::CustomBeatmapSaveData *> CustomJSONData::v3::Parser::ParsedEvent;

DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_ColorNoteData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_BombNoteData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_ObstacleData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_BurstSliderData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_SliderData);
DEFINE_TYPE(CustomJSONData::v3, CustomBeatmapSaveData_BasicEventData);

//#define SAFEPTR_VLIST_ARG(type, name, ...) \
//    SafePtr<System::Collections::Generic::List_1<type>> name##Ptr(System::Collections::Generic::List_1<type>::New_ctor(__VA_ARGS__)); \
//    VList<type> name(static_cast<System::Collections::Generic::List_1<type>*>(name##Ptr));
//
//#define SAFEPTR_VLIST(type, name) \
//    SafePtr<System::Collections::Generic::List_1<type>> name##Ptr(System::Collections::Generic::List_1<type>::New_ctor(0)); \
//    VList<type> name(static_cast<System::Collections::Generic::List_1<type>*>(name##Ptr));

#define SAFEPTR_VLIST_ARG(type, name, ...) \
    VList<type> name(CustomJSONData::NewFast<System::Collections::Generic::List_1<type>*>(__VA_ARGS__));

#define SAFEPTR_VLIST(type, name) SAFEPTR_VLIST_ARG(type, name)

void CustomBeatmapSaveData::ctor(
        System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::BpmChangeEventData *> *bpmEvents,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::RotationEventData *> *rotationEvents,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::ColorNoteData *> *colorNotes,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::BombNoteData *> *bombNotes,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::ObstacleData *> *obstacles,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::SliderData *> *sliders,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::BurstSliderData *> *burstSliders,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::WaypointData *> *waypoints,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::BasicEventData *> *basicBeatmapEvents,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::ColorBoostEventData *> *colorBoostBeatmapEvents,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::LightColorEventBoxGroup *> *lightColorEventBoxGroups,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::LightRotationEventBoxGroup *> *lightRotationEventBoxGroups,
        ::System::Collections::Generic::List_1<::BeatmapSaveDataVersion3::BeatmapSaveData::LightTranslationEventBoxGroup *> *lightTranslationEventBoxGroups,
        ::BeatmapSaveDataVersion3::BeatmapSaveData::BasicEventTypesWithKeywords *basicEventTypesWithKeywords,
        bool useNormalEventsAsCompatibleEvents) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData*), ".ctor", 15);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, bpmEvents,
                                         rotationEvents,
                                         colorNotes,
                                         bombNotes,
                                         obstacles,
                                         sliders,
                                         burstSliders,
                                         waypoints,
                                         basicBeatmapEvents,
                                         colorBoostBeatmapEvents,
                                         lightColorEventBoxGroups,
                                         lightRotationEventBoxGroups,
                                         lightTranslationEventBoxGroups,
                                         basicEventTypesWithKeywords,
                                         useNormalEventsAsCompatibleEvents));
}

void CustomBeatmapSaveData_ColorNoteData::ctor(float beat, int line, int layer,
                                               ::BeatmapSaveDataVersion3::BeatmapSaveData::NoteColorType color,
                                               ::GlobalNamespace::NoteCutDirection cutDirection, int angleOffset) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::ColorNoteData*), ".ctor", 6);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, beat, line, layer, color, cutDirection, angleOffset));
}

void CustomBeatmapSaveData_BombNoteData::ctor(float beat, int line, int layer) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::BombNoteData*), ".ctor", 3);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, beat, line, layer));
}

void CustomBeatmapSaveData_SliderData::ctor(BeatmapSaveDataVersion3::BeatmapSaveData::NoteColorType colorType,
                                            float headBeat, int headLine, int headLayer,
                                            float headControlPointLengthMultiplier,
                                            ::GlobalNamespace::NoteCutDirection headCutDirection, float tailBeat,
                                            int tailLine, int tailLayer, float tailControlPointLengthMultiplier,
                                            ::GlobalNamespace::NoteCutDirection tailCutDirection,
                                            ::GlobalNamespace::SliderMidAnchorMode sliderMidAnchorMode) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::SliderData*), ".ctor", 12);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, colorType, headBeat, headLine, headLayer,
                                         headControlPointLengthMultiplier, headCutDirection, tailBeat, tailLine,
                                         tailLayer, tailControlPointLengthMultiplier, tailCutDirection,
                                         sliderMidAnchorMode));
}

void CustomBeatmapSaveData_BurstSliderData::ctor(BeatmapSaveDataVersion3::BeatmapSaveData::NoteColorType colorType,
                                                 float headBeat, int headLine, int headLayer,
                                                 ::GlobalNamespace::NoteCutDirection headCutDirection, float tailBeat,
                                                 int tailLine, int tailLayer, int sliceCount, float squishAmount) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::BurstSliderData*), ".ctor", 10);
    CRASH_UNLESS(
            il2cpp_utils::RunMethod(this, ctor, colorType, headBeat, headLine, headLayer, headCutDirection, tailBeat,
                                    tailLine, tailLayer, sliceCount, squishAmount));
}

void CustomBeatmapSaveData_ObstacleData::ctor(float beat, int line, int layer, float duration, int width, int height) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::ObstacleData*), ".ctor", 6);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, beat, line, layer, duration, width, height));
}


void CustomJSONData::v3::CustomBeatmapSaveData_BasicEventData::ctor(float time,
                                                                    BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType type,
                                                                    int value, float floatValue) {
    INVOKE_CTOR();
    static auto *ctor = il2cpp_utils::FindMethodUnsafe(classof(BeatmapSaveData::BasicEventData*), ".ctor", 4);
    CRASH_UNLESS(il2cpp_utils::RunMethod(this, ctor, time, type, value, floatValue));
}

inline decltype(CustomJSONData::v3::CustomBeatmapSaveData::customData) GetCustomData(rapidjson::Value const &doc) {
    auto customDataIt = doc.FindMember(Constants::customData);
    if (customDataIt != doc.MemberEnd() && customDataIt->value.IsObject()) {
        return customDataIt->value;
    }

    return std::nullopt;
}

#define IT_HASH auto nameHash = std::hash<std::string_view>()(it.name.GetString());

#define IF_CHECK_HASH_FROM_CONSTANTS(str) \
        static const auto str##_Hash = std::hash<std::string_view>()(Constants::str); \
        if (nameHash == str##_Hash)

#define IF_CHECK_HASH(str) \
        static const auto str##_Hash = std::hash<std::string_view>()(#str); \
        if (nameHash == str##_Hash)

static inline bool ParseBool(rapidjson::Value const &val) {
    if (val.IsNumber()) {
        return val.GetInt() == 1;
    }
    if (val.IsString()) {
        return std::string_view(val.GetString()) == "true";
    }
    if (!val.IsBool()) {
        return false;
    }

    return val.GetBool();
}

static auto DeserializeBpmChangeEventData(rapidjson::Value const &val) {
    float beat;
    float bpm;


    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH(m) {
            bpm = it.value.GetFloat();
        }
    }


    return CustomJSONData::NewFast<BeatmapSaveData::BpmChangeEventData *>(beat, bpm);
}

static auto DeserializeRotation(rapidjson::Value const &val) {
    float beat;
    BeatmapSaveData::ExecutionTime executionTime;
    float rotation;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH(e) {
            executionTime = it.value.GetInt();
        }

        IF_CHECK_HASH(r) {
            rotation = it.value.GetFloat();
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::RotationEventData *>(beat, executionTime, rotation);
}

CustomBeatmapSaveData_ColorNoteData *CustomJSONData::v3::Parser::DeserializeColorNote(rapidjson::Value const &val) {

    float beat;
    int line;
    int layer;
    BeatmapSaveData::NoteColorType color;
    NoteCutDirection cutDirection;
    int angleOffset;
    CustomDataOpt customData;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            line = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            layer = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(colorType) {
            color = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(cutDirection) {
            cutDirection = it.value.GetInt();
        }

        IF_CHECK_HASH(a) {
            angleOffset = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            customData = it.value;
        }
    }

    auto note = CustomBeatmapSaveData_ColorNoteData::New_ctor(beat, line, layer, color, cutDirection, angleOffset);
    note->customData = CustomJSONData::JSONWrapperOrNull(customData);

    return note;
}

CustomBeatmapSaveData_BombNoteData *CustomJSONData::v3::Parser::DeserializeBombNote(rapidjson::Value const &val) {
    float beat;
    int line;
    int layer;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            line = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            layer = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto bomb = CustomBeatmapSaveData_BombNoteData::New_ctor(beat, line, layer);
    bomb->customData = CustomJSONData::JSONWrapperOrNull(data);

    return bomb;
}

CustomBeatmapSaveData_ObstacleData *CustomJSONData::v3::Parser::DeserializeObstacle(rapidjson::Value const &val) {
    float beat;
    int line;
    int layer;
    float duration;
    int width;
    int height;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            line = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            layer = it.value.GetInt();
        }

        IF_CHECK_HASH(d) {
            duration = it.value.GetFloat();
        }

        IF_CHECK_HASH(w) {
            width = it.value.GetInt();
        }

        IF_CHECK_HASH(h) {
            height = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto obstacle = CustomBeatmapSaveData_ObstacleData::New_ctor(beat, line, layer, duration, width, height);
    obstacle->customData = CustomJSONData::JSONWrapperOrNull(data);
    return obstacle;
}

CustomBeatmapSaveData_SliderData *CustomJSONData::v3::Parser::DeserializeSlider(rapidjson::Value const &val) {
    BeatmapSaveData::NoteColorType color;
    float headBeat;
    int headLine;
    int headLayer;
    float headControlPointLengthMultiplier;
    NoteCutDirection headCutDirection;
    float tailBeat;
    int tailLine;
    int tailLayer;
    float tailControlPointLengthMultiplier;
    NoteCutDirection tailCutDirection;
    SliderMidAnchorMode sliderMidAnchorMode;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(colorType) {
            color = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            headBeat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            headLine = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            headLayer = it.value.GetInt();
        }

        IF_CHECK_HASH(mu) {
            headControlPointLengthMultiplier = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(cutDirection) {
            headCutDirection = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailBeat) {
            tailBeat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailLine) {
            tailLine = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailLayer) {
            tailLayer = it.value.GetInt();
        }

        IF_CHECK_HASH(tmu) {
            tailControlPointLengthMultiplier = it.value.GetFloat();
        }

        IF_CHECK_HASH(tc) {
            tailCutDirection = it.value.GetInt();
        }

        IF_CHECK_HASH(m) {
            sliderMidAnchorMode = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto slider = CustomBeatmapSaveData_SliderData::New_ctor(
            color,
            headBeat,
            headLine,
            headLayer,
            headControlPointLengthMultiplier,
            headCutDirection,
            tailBeat,
            tailLine,
            tailLayer,
            tailControlPointLengthMultiplier,
            tailCutDirection,
            sliderMidAnchorMode);

    slider->customData = CustomJSONData::JSONWrapperOrNull(data);

    return slider;
}


CustomJSONData::v3::CustomBeatmapSaveData_BurstSliderData *
CustomJSONData::v3::Parser::DeserializeBurstSlider(rapidjson::Value const &val) {
    BeatmapSaveData::NoteColorType color;
    float headBeat;
    int headLine;
    int headLayer;
    NoteCutDirection headCutDirection;
    float tailBeat;
    int tailLine;
    int tailLayer;
    int sliceCount;
    float squishAmount;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(colorType) {
            color = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            headBeat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            headLine = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            headLayer = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(cutDirection) {
            headCutDirection = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailBeat) {
            tailBeat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailLine) {
            tailLine = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(tailLayer) {
            tailLayer = it.value.GetInt();
        }

        IF_CHECK_HASH(sc) {
            sliceCount = it.value.GetInt();
        }

        IF_CHECK_HASH(s) {
            squishAmount = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto slider = CustomBeatmapSaveData_BurstSliderData::New_ctor(
            color,
            headBeat,
            headLine,
            headLayer,
            headCutDirection,
            tailBeat,
            tailLine,
            tailLayer,
            sliceCount,
            squishAmount);

    slider->customData = CustomJSONData::JSONWrapperOrNull(data);

    return slider;
}

static auto DeserializeWaypoint(rapidjson::Value const &val) {
    float beat;
    int line;
    int layer;
    OffsetDirection offsetDirection;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(line) {
            line = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(layer) {
            layer = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(cutDirection) {
            offsetDirection = it.value.GetInt();
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::WaypointData *>(beat, line, layer, offsetDirection);
}

static auto DeserializeBasicEvent(rapidjson::Value const &val) {
    float beat;
    BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType eventType;
    int value;
    float floatValue;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH(et) {
            eventType = it.value.GetInt();
        }

        IF_CHECK_HASH(i) {
            value = it.value.GetInt();
        }

        IF_CHECK_HASH(f) {
            floatValue = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto event = CustomBeatmapSaveData_BasicEventData::New_ctor(beat, eventType, value, floatValue);
    event->customData = CustomJSONData::JSONObjectOrNull(data);
    return event;
}

static auto DeserializeColorBoostEventData(rapidjson::Value const &val) {
    float beat;
    bool boost;
    CustomDataOpt data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH(o) {
            boost = ParseBool(it.value);
        }

        IF_CHECK_HASH_FROM_CONSTANTS(customData) {
            data = it.value;
        }
    }

    auto event = CustomJSONData::NewFast<BeatmapSaveData::ColorBoostEventData *>(beat, boost);
//    event->customData = CustomJSONData::JSONObjectOrNull(data);
    return event;
}

static auto DeserializeIndexFilter(rapidjson::Value const &val) {
    BeatmapSaveData::IndexFilter::IndexFilterType type = 0;
    int param0 = 0;
    int param1 = 0;
    bool reversed = false;
    BeatmapSaveData::IndexFilterRandomType random = 0;
    int seed = 0;
    int chunks = 0;
    float limit = 0;
    BeatmapSaveData::IndexFilterLimitAlsoAffectsType limitAlsoAffectsType = 0;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH(f) {
            type = it.value.GetInt();
        }

        IF_CHECK_HASH(p) {
            param0 = it.value.GetInt();
        }

        IF_CHECK_HASH(t) {
            param1 = it.value.GetInt();
        }

        IF_CHECK_HASH(r) {
            reversed = ParseBool(it.value);
        }

        IF_CHECK_HASH(c) {
            chunks = it.value.GetInt();
        }

        IF_CHECK_HASH(l) {
            limit = it.value.GetFloat();
        }

        IF_CHECK_HASH(d) {
            limitAlsoAffectsType = it.value.GetInt();
        }

        IF_CHECK_HASH(n) {
            random = it.value.GetInt();
        }

        IF_CHECK_HASH(s) {
            seed = it.value.GetInt();
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::IndexFilter *>(type, param0, param1, reversed, random, seed, chunks,
                                                                   limit, limitAlsoAffectsType);
}

static auto DeserializeLightColorEventBoxGroup(rapidjson::Value const &val) {
    float beat;
    SAFEPTR_VLIST(BeatmapSaveData::LightColorEventBox*, eventBoxes);
    int groupId;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(groupId) {
            groupId = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(eventBoxes) {
            // idc if it shadows
            for (auto const &arrIt: it.value.GetArray()) {

                /* nullable */ BeatmapSaveData::IndexFilter *indexFilter;
                float beatDistributionParam;
                BeatmapSaveData::EventBox::DistributionParamType beatDistributionParamType;
                float brightnessDistributionParam;
                bool brightnessDistributionShouldAffectFirstBaseEvent;
                BeatmapSaveData::EventBox::DistributionParamType brightnessDistributionParamType;
                EaseType brightnessDistributionEaseType;
                SAFEPTR_VLIST(BeatmapSaveData::LightColorBaseData*, lightColorBaseDataList);

                for (auto const &it: arrIt.GetObject()) {
                    IT_HASH

                    IF_CHECK_HASH_FROM_CONSTANTS(indexFilter) {
                        indexFilter = DeserializeIndexFilter(it.value);
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParam) {
                        beatDistributionParam = it.value.GetFloat();
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParamType) {
                        beatDistributionParamType = it.value.GetInt();
                    }

                    IF_CHECK_HASH(r) {
                        brightnessDistributionParam = it.value.GetFloat();
                    }

                    IF_CHECK_HASH(b) {
                        brightnessDistributionShouldAffectFirstBaseEvent = ParseBool(it.value);
                    }

                    IF_CHECK_HASH(t) {
                        brightnessDistributionParamType = it.value.GetInt();
                    }
                    IF_CHECK_HASH(i) {
                        brightnessDistributionEaseType = it.value.GetInt();
                    }

                    IF_CHECK_HASH(e) {
                        for (auto const &arrIt: it.value.GetArray()) {
                            float lightBeat;
                            BeatmapSaveData::TransitionType transitionType;
                            BeatmapSaveData::EnvironmentColorType colorType;
                            float brightness;
                            int strobeFrequency;

                            for (auto const &it: arrIt.GetObject()) {
                                IT_HASH

                                IF_CHECK_HASH_FROM_CONSTANTS(beat) {
                                    lightBeat = it.value.GetFloat();
                                }

                                IF_CHECK_HASH(i) {
                                    transitionType = it.value.GetInt();
                                }

                                IF_CHECK_HASH_FROM_CONSTANTS(colorType) {
                                    colorType = it.value.GetInt();
                                }

                                IF_CHECK_HASH(s) {
                                    brightness = it.value.GetFloat();
                                }

                                IF_CHECK_HASH(f) {
                                    strobeFrequency = it.value.GetInt();
                                }
                            }

                            lightColorBaseDataList.push_back(
                                    CustomJSONData::NewFast<BeatmapSaveData::LightColorBaseData *>(lightBeat,
                                                                                                   transitionType,
                                                                                                   colorType,
                                                                                                   brightness,
                                                                                                   strobeFrequency));
                        }
                    }
                }

                CRASH_UNLESS(indexFilter);

                eventBoxes.push_back(CustomJSONData::NewFast<BeatmapSaveData::LightColorEventBox *>(
                        indexFilter,
                        beatDistributionParam,
                        beatDistributionParamType,
                        brightnessDistributionParam,
                        brightnessDistributionShouldAffectFirstBaseEvent,
                        brightnessDistributionParamType,
                        (int)brightnessDistributionEaseType,
                        lightColorBaseDataList.getInner()));
            }
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::LightColorEventBoxGroup *>(beat, groupId, eventBoxes.getInner());
}

static auto DeserializeLightRotationEventBoxGroup(rapidjson::Value const &val) {
    float beat;
    SAFEPTR_VLIST(BeatmapSaveData::LightRotationEventBox*, eventBoxes);
    int groupId;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(groupId) {
            groupId = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(eventBoxes) {
            auto arr = it.value.GetArray();

            eventBoxes.resize(arr.Size());

            // idc if it shadows
            for (auto const &arrIt: arr) {

                /* nullable */ BeatmapSaveData::IndexFilter *indexFilter = nullptr;
                float beatDistributionParam;
                BeatmapSaveData::EventBox::DistributionParamType beatDistributionParamType;
                float rotationDistributionParam;
                BeatmapSaveData::EventBox::DistributionParamType rotationDistributionParamType;
                bool rotationDistributionShouldAffectFirstBaseEvent;
                BeatmapSaveData::Axis axis;
                bool flipRotation;
                EaseType rotationDistributionEaseType;
                SAFEPTR_VLIST(BeatmapSaveData::LightRotationBaseData*, lightRotationBaseDataList);

                for (auto const &it: arrIt.GetObject()) {
                    IT_HASH

                    IF_CHECK_HASH_FROM_CONSTANTS(indexFilter) {
                        indexFilter = DeserializeIndexFilter(it.value);
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParam) {
                        beatDistributionParam = it.value.GetFloat();
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParamType) {
                        beatDistributionParamType = it.value.GetInt();
                    }

                    IF_CHECK_HASH(s) {
                        rotationDistributionParam = it.value.GetFloat();
                    }

                    IF_CHECK_HASH(t) {
                        rotationDistributionParamType = it.value.GetInt();
                    }

                    IF_CHECK_HASH(b) {
                        rotationDistributionShouldAffectFirstBaseEvent = ParseBool(it.value);
                    }

                    IF_CHECK_HASH(a) {
                        axis = it.value.GetInt();
                    }

                    IF_CHECK_HASH(r) {
                        flipRotation = ParseBool(it.value);
                    }

                    IF_CHECK_HASH(l) {
                        auto arr = it.value.GetArray();
                        lightRotationBaseDataList.resize(arr.Size());

                        for (auto const &arrIt: arr) {
                            float lightBeat;
                            bool usePreviousEventRotationValue;
                            BeatmapSaveData::EaseType easeType;
                            int loopsCount;
                            float rotation;
                            BeatmapSaveData::LightRotationBaseData::RotationDirection rotationDirection;

                            for (auto const &it: arrIt.GetObject()) {
                                IT_HASH

                                IF_CHECK_HASH_FROM_CONSTANTS(beat) {
                                    lightBeat = it.value.GetFloat();
                                }

                                IF_CHECK_HASH(p) {
                                    usePreviousEventRotationValue = ParseBool(it.value);
                                }

                                IF_CHECK_HASH(e) {
                                    easeType = it.value.GetInt();
                                }

                                IF_CHECK_HASH(l) {
                                    loopsCount = it.value.GetInt();
                                }

                                IF_CHECK_HASH(r) {
                                    rotation = it.value.GetFloat();
                                }

                                IF_CHECK_HASH(o) {
                                    rotationDirection = it.value.GetInt();
                                }
                                IF_CHECK_HASH(i) {
                                    rotationDistributionEaseType = it.value.GetInt();
                                }
                            }

                            lightRotationBaseDataList.push_back(
                                    CustomJSONData::NewFast<BeatmapSaveData::LightRotationBaseData *>(
                                            lightBeat,
                                            usePreviousEventRotationValue,
                                            easeType,
                                            loopsCount,
                                            rotation,
                                            rotationDirection));
                        }
                    }
                }

                eventBoxes.push_back(CustomJSONData::NewFast<BeatmapSaveData::LightRotationEventBox *>(
                        indexFilter,
                        beatDistributionParam,
                        beatDistributionParamType,
                        rotationDistributionParam,
                        rotationDistributionParamType,
                        rotationDistributionShouldAffectFirstBaseEvent,
                        (int)rotationDistributionEaseType,
                        axis,
                        flipRotation,
                        lightRotationBaseDataList.getInner()));
            }
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::LightRotationEventBoxGroup *>(beat, groupId, eventBoxes.getInner());
}

static auto DeserializeLightTranslationEventBoxGroup(rapidjson::Value const &val) {
    float beat;
    SAFEPTR_VLIST(BeatmapSaveData::LightTranslationEventBox*, eventBoxes);
    int groupId;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            beat = it.value.GetFloat();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(groupId) {
            groupId = it.value.GetInt();
        }

        IF_CHECK_HASH_FROM_CONSTANTS(eventBoxes) {
            auto arr = it.value.GetArray();

            eventBoxes.resize(arr.Size());

            // idc if it shadows
            for (auto const &arrIt: arr) {

                /* nullable */ BeatmapSaveData::IndexFilter *indexFilter = nullptr;
                float beatDistributionParam;
                BeatmapSaveData::EventBox::DistributionParamType beatDistributionParamType;
                float gapDistributionParam;
                BeatmapSaveData::EventBox::DistributionParamType gapDistributionParamType;
                bool gapDistributionShouldAffectFirstBaseEvent;
                BeatmapSaveData::Axis axis;
                bool flipTranslation;
                EaseType gapDistributionEaseType;
                SAFEPTR_VLIST(BeatmapSaveData::LightTranslationBaseData*, lightTranslationBaseDataList );

                for (auto const &it: arrIt.GetObject()) {
                    IT_HASH

                    IF_CHECK_HASH_FROM_CONSTANTS(indexFilter) {
                        indexFilter = DeserializeIndexFilter(it.value);
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParam) {
                        beatDistributionParam = it.value.GetFloat();
                    }

                    IF_CHECK_HASH_FROM_CONSTANTS(beatDistributionParamType) {
                        beatDistributionParamType = it.value.GetInt();
                    }
                    // gapDistributionParam float
                    IF_CHECK_HASH(s) {
                        gapDistributionParam = it.value.GetFloat();
                    }

                    // gapDistributionParamType (1 - wave, 2 - step)
                    IF_CHECK_HASH(t) {
                        gapDistributionParamType = it.value.GetInt();
                    }

                    // gapDistributionShouldAffectFirstBaseEvent (bool) (0, 1) as int
                    IF_CHECK_HASH(b) {
                        gapDistributionShouldAffectFirstBaseEvent = ParseBool(it.value);
                    }

                    // axis (0 - x, 1 - y, 2 - z)
                    IF_CHECK_HASH(a) {
                        axis = it.value.GetInt();
                    }

                    // flipTranslation (bool) (0, 1) as int
                    IF_CHECK_HASH(r) {
                        flipTranslation = ParseBool(it.value);
                    }

                    // gapDistributionShouldAffectFirstBaseEvent (-1 - None, 0 - Linear, 1 - InQuad, 2 - OutQuad, 3 - InOutQuad)
                    IF_CHECK_HASH(i) {
                        gapDistributionEaseType = it.value.GetInt();
                    }

                    // lightTranslationBaseDataList (array)
                    IF_CHECK_HASH(l) {
                        auto arr = it.value.GetArray();
                        lightTranslationBaseDataList.resize(arr.Size());

                        for (auto const &arrIt: arr) {
                            float lightBeat;
                            bool usePreviousEventTransitionValue;
                            BeatmapSaveData::EaseType easeType;
                            float translation;

                            for (auto const &it: arrIt.GetObject()) {
                                IT_HASH

                                // beat float
                                IF_CHECK_HASH_FROM_CONSTANTS(beat) {
                                    lightBeat = it.value.GetFloat();
                                }

                                // usePreviousEventTranslationValue (bool) (0, 1) as int
                                IF_CHECK_HASH(p) {
                                    usePreviousEventTransitionValue = ParseBool(it.value);
                                }

                                // easeType (-1 - None, 0 - Linear, 1 - InQuad, 2 - OutQuad, 3 - InOutQuad)
                                IF_CHECK_HASH(e) {
                                    easeType = it.value.GetInt();
                                }

                                // translation float
                                IF_CHECK_HASH(t) {
                                    translation = it.value.GetFloat();
                                }
                            }

                            lightTranslationBaseDataList.push_back(
                                    CustomJSONData::NewFast<BeatmapSaveData::LightTranslationBaseData *>(
                                            lightBeat,
                                            usePreviousEventTransitionValue,
                                            (int)easeType,
                                            translation));
                        }
                    }
                }

                eventBoxes.push_back(CustomJSONData::NewFast<BeatmapSaveData::LightTranslationEventBox *>(
                        indexFilter,
                        beatDistributionParam,
                        (int)beatDistributionParamType,
                        gapDistributionParam,
                        (int)gapDistributionParamType,
                        gapDistributionShouldAffectFirstBaseEvent,
                        (int)gapDistributionEaseType,
                        axis,
                        flipTranslation,
                        lightTranslationBaseDataList.getInner()));
            }
        }
    }

    return CustomJSONData::NewFast<BeatmapSaveData::LightTranslationEventBoxGroup  *>(beat, groupId, eventBoxes.getInner());
}

static auto DeserializeBasicEventTypesForKeyword(rapidjson::Value const &val) {
    std::string_view keyword;

    SAFEPTR_VLIST(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType, eventTypes);

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH(k) {
            keyword = it.value.GetString();
        }

        IF_CHECK_HASH(e) {
            auto const &arr = it.value.GetArray();
            eventTypes.resize(arr.Size());

            for (auto const &arrIt: arr) {
                eventTypes.push_back(it.value.GetInt());
            }
        }
    }

    return BeatmapSaveData::BasicEventTypesWithKeywords::BasicEventTypesForKeyword::New_ctor(keyword,
                                                                                             eventTypes.getInner());
}

static auto DeserializeCustomEvent(rapidjson::Value const &val) {
    float beat;
    std::string_view type;
    rapidjson::Value const *data;

    for (auto const &it: val.GetObject()) {
        IT_HASH

        IF_CHECK_HASH_FROM_CONSTANTS(beat) {
            if (it.value.IsString()) {
                beat = std::stof(it.value.GetString());
            } else {
                beat = it.value.GetFloat();
            }
        }

        IF_CHECK_HASH(t) {
            type = it.value.GetString();
        }

        IF_CHECK_HASH(d) {
            data = &it.value;
        }
    }

    return CustomJSONData::CustomEventSaveData(type, beat, data);
}

CustomJSONData::v3::CustomBeatmapSaveData *
CustomJSONData::v3::CustomBeatmapSaveData::Deserialize(std::shared_ptr<rapidjson::Document> sharedDoc) {
    using namespace Parser;

    auto const &doc = *sharedDoc;

    SAFEPTR_VLIST(BeatmapSaveData::BpmChangeEventData*, bpmEvents);
    SAFEPTR_VLIST(BeatmapSaveData::RotationEventData*, rotationEvents);
    SAFEPTR_VLIST(BeatmapSaveData::ColorNoteData*, colorNotes);
    SAFEPTR_VLIST(BeatmapSaveData::BombNoteData*, bombNotes);
    SAFEPTR_VLIST(BeatmapSaveData::ObstacleData*, obstacles);
    SAFEPTR_VLIST(BeatmapSaveData::SliderData*, sliders);
    SAFEPTR_VLIST(BeatmapSaveData::BurstSliderData*, burstSliders);
    SAFEPTR_VLIST(BeatmapSaveData::WaypointData*, waypoints);
    SAFEPTR_VLIST(BeatmapSaveData::BasicEventData*, basicBeatmapEvents);
    SAFEPTR_VLIST(BeatmapSaveData::ColorBoostEventData*, colorBoostBeatmapEvents);
    SAFEPTR_VLIST(BeatmapSaveData::LightColorEventBoxGroup*, lightColorEventBoxGroups);
    SAFEPTR_VLIST(BeatmapSaveData::LightRotationEventBoxGroup*, lightRotationEventBoxGroups);
    SAFEPTR_VLIST(BasicEventTypesWithKeywords::BasicEventTypesForKeyword *, basicEventTypesForKeyword);
    SAFEPTR_VLIST(LightTranslationEventBoxGroup *, lightTranslationEventBoxGroups);
    bool useNormalEventsAsCompatibleEvents;

    for (auto const &it: doc.GetObject()) {
        IT_HASH

        IF_CHECK_HASH(bpmEvents) {
            auto arr = it.value.GetArray();
            bpmEvents.resize(arr.Size());

            for (auto const &o: arr) {
                bpmEvents.push_back(DeserializeBpmChangeEventData(o));
            }
        }

        IF_CHECK_HASH(rotationEvents) {
            auto arr = it.value.GetArray();
            rotationEvents.resize(arr.Size());

            for (auto const &o: arr) {
                rotationEvents.push_back(DeserializeRotation(o));
            }
        }
        IF_CHECK_HASH(colorNotes) {
            auto arr = it.value.GetArray();
            colorNotes.resize(arr.Size());

            for (auto const &o: arr) {
                colorNotes.push_back(CRASH_UNLESS(DeserializeColorNote(o)));
            }
        }
        IF_CHECK_HASH(bombNotes) {
            auto arr = it.value.GetArray();
            bombNotes.resize(arr.Size());

            for (auto const &o: arr) {
                bombNotes.push_back(DeserializeBombNote(o));
            }
        }
        IF_CHECK_HASH(obstacles) {
            auto arr = it.value.GetArray();
            obstacles.resize(arr.Size());

            for (auto const &o: arr) {
                obstacles.push_back(DeserializeObstacle(o));
            }
        }
        IF_CHECK_HASH(sliders) {
            auto arr = it.value.GetArray();
            sliders.resize(arr.Size());

            for (auto const &o: arr) {
                sliders.push_back(DeserializeSlider(o));
            }
        }
        IF_CHECK_HASH(burstSliders) {
            auto arr = it.value.GetArray();
            burstSliders.resize(arr.Size());

            for (auto const &o: arr) {
                burstSliders.push_back(DeserializeBurstSlider(o));
            }
        }
        IF_CHECK_HASH(waypoints) {
            auto arr = it.value.GetArray();

            waypoints.resize(arr.Size());

            for (auto const &o: arr) {
                waypoints.push_back(DeserializeWaypoint(o));
            }
        }
        IF_CHECK_HASH(basicBeatmapEvents) {
            auto arr = it.value.GetArray();

            basicBeatmapEvents.resize(arr.Size());

            for (auto const &o: arr) {
                basicBeatmapEvents.push_back(DeserializeBasicEvent(o));
            }
        }
        IF_CHECK_HASH(colorBoostBeatmapEvents) {
            auto arr = it.value.GetArray();

            colorBoostBeatmapEvents.resize(arr.Size());

            for (auto const &o: arr) {
                colorBoostBeatmapEvents.push_back(DeserializeColorBoostEventData(o));
            }
        }
        IF_CHECK_HASH(lightColorEventBoxGroups) {
            auto arr = it.value.GetArray();

            lightColorEventBoxGroups.resize(arr.Size());

            for (auto const &o: arr) {
                lightColorEventBoxGroups.push_back(DeserializeLightColorEventBoxGroup(o));
            }
        }
        IF_CHECK_HASH(lightRotationEventBoxGroups) {
            auto arr = it.value.GetArray();

            lightRotationEventBoxGroups.resize(arr.Size());

            for (auto const &o: it.value.GetArray()) {
                lightRotationEventBoxGroups.push_back(DeserializeLightRotationEventBoxGroup(o));
            }
        }
        IF_CHECK_HASH(lightTranslationEventBoxGroups) {
            auto arr = it.value.GetArray();

            lightTranslationEventBoxGroups.resize(arr.Size());

            for (auto const &o: it.value.GetArray()) {
                lightTranslationEventBoxGroups.push_back(DeserializeLightTranslationEventBoxGroup(o));
            }
        }
        IF_CHECK_HASH(basicEventTypesWithKeywords) {

            auto dIt = it.value.FindMember("d");

            if (dIt != it.value.MemberEnd()) {
                auto arr = dIt->value.GetArray();

                basicEventTypesForKeyword.resize(arr.Size());

                for (auto const &it: arr) {
                    basicEventTypesForKeyword.push_back(DeserializeBasicEventTypesForKeyword(it));
                }
            }
        }
        IF_CHECK_HASH(useNormalEventsAsCompatibleEvents) {
            useNormalEventsAsCompatibleEvents = it.value.GetBool();
        }
    }

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Parse bpm events {}", bpmEvents.size());
    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Parse notes {}", colorNotes.size());

    auto customEvents = std::make_shared<std::vector<CustomJSONData::CustomEventSaveData>>();
    CustomDataOpt dataOpt = GetCustomData(doc);

    if (dataOpt) {
        auto customEventsIt = dataOpt->get().FindMember("customEvents");
        if (customEventsIt != dataOpt->get().MemberEnd() && !customEventsIt->value.IsNull()) {
            customEvents->reserve(customEventsIt->value.GetArray().Size());
            for (auto const &it: customEventsIt->value.GetArray()) {
                customEvents->emplace_back(DeserializeCustomEvent(it));
            }
        }
    }

    auto beatmap = CustomBeatmapSaveData::New_ctor(
            bpmEvents.getInner(),
            rotationEvents.getInner(),
            colorNotes.getInner(),
            bombNotes.getInner(),
            obstacles.getInner(),
            sliders.getInner(),
            burstSliders.getInner(),
            waypoints.getInner(),
            basicBeatmapEvents.getInner(),
            colorBoostBeatmapEvents.getInner(),
            lightColorEventBoxGroups.getInner(),
            lightRotationEventBoxGroups.getInner(),
            lightTranslationEventBoxGroups,
            BasicEventTypesWithKeywords::New_ctor(basicEventTypesForKeyword.getInner()),
            useNormalEventsAsCompatibleEvents);

    beatmap->customData = CustomJSONData::JSONObjectOrNull(dataOpt);
    beatmap->doc = sharedDoc;
    beatmap->customEventsData = customEvents;

    Parser::ParsedEvent.invoke(beatmap);
    return beatmap;
}

static inline const std::array<float, 8> spawnRotations
        {
                -60.0f,
                -45.0f,
                -30.0f,
                -15.0f,
                15.0f,
                30.0f,
                45.0f,
                60.0f
        };

template<typename T>
constexpr bool TimeCompare(T const &a, T const &b) {
    return (a->time < b->time);
}


constexpr bool TimeCompareSliders(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::SliderData *const &a,
                                  BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::SliderData *const &b) {
    return (a->headTime < b->headTime);
}

constexpr BeatmapSaveData::NoteColorType
GetNoteColorType(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::NoteType noteType) {
    return noteType == BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::NoteType::NoteB
           ? BeatmapSaveData::NoteColorType::ColorB
           : BeatmapSaveData::NoteColorType::ColorA;
}

constexpr BeatmapSaveData::NoteColorType
GetNoteColorType(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ColorType colorType) {
    return colorType == BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ColorType::ColorB
           ? BeatmapSaveData::NoteColorType::ColorB
           : BeatmapSaveData::NoteColorType::ColorA;
}

constexpr int
GetHeightForObstacleType(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ObstacleType obstacleType) {
    return obstacleType != BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ObstacleType::Top ? 5 : 3;
}

constexpr int
GetLayerForObstacleType(BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ObstacleType obstacleType) {
    return obstacleType != BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ObstacleType::Top ? 0 : 2;
}

constexpr float SpawnRotationForEventValue(int index) {
    if (index >= 0 && index < spawnRotations.size()) {
        return spawnRotations[index];
    }

    return 0.0f;
}


CustomBeatmapSaveData *CustomBeatmapSaveData::Convert2_6_0(CustomJSONData::v2::CustomBeatmapSaveData const *beatmap) {
    auto startTime = std::chrono::high_resolution_clock::now();
    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Initiating converting 2.0.0 to 3.0.0 map");

    SAFEPTR_VLIST_ARG(BeatmapSaveData::ColorNoteData*, colorNotes, beatmap->notes->get_Count());
    SAFEPTR_VLIST_ARG(BeatmapSaveData::BombNoteData*, bombNotes, beatmap->notes->get_Count());
    SAFEPTR_VLIST_ARG(BeatmapSaveData::SliderData*, sliders, beatmap->sliders->get_Count());
    SAFEPTR_VLIST_ARG(BeatmapSaveData::ObstacleData*, obstacles, beatmap->obstacles->get_Count());
    SAFEPTR_VLIST_ARG(BeatmapSaveData::WaypointData*, waypoints, beatmap->waypoints->get_Count());

    SAFEPTR_VLIST(BeatmapSaveData::ColorBoostEventData*, colorBoosts);
    SAFEPTR_VLIST(BeatmapSaveData::RotationEventData*, rotationEvents);
    SAFEPTR_VLIST(BeatmapSaveData::BpmChangeEventData*, bpmChanges);
    SAFEPTR_VLIST(BeatmapSaveData::BasicEventData*, basicEvents);


    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Sorting");
    std::stable_sort(beatmap->notes->items.begin(), beatmap->notes->items.begin() + beatmap->notes->get_Count(),
                     TimeCompare<BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::NoteData *>);
    std::stable_sort(beatmap->obstacles->items.begin(),
                     beatmap->obstacles->items.begin() + beatmap->obstacles->get_Count(),
                     TimeCompare<BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::ObstacleData *>);
    std::stable_sort(beatmap->sliders->items.begin(), beatmap->sliders->items.begin() + beatmap->sliders->get_Count(),
                     TimeCompareSliders);
    std::stable_sort(beatmap->waypoints->items.begin(),
                     beatmap->waypoints->items.begin() + beatmap->waypoints->get_Count(),
                     TimeCompare<BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::WaypointData *>);
    std::stable_sort(beatmap->events->items.begin(), beatmap->events->items.begin() + beatmap->events->get_Count(),
                     TimeCompare<BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::EventData *>);

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting notes");
    for (auto const &n: VList(beatmap->notes)) {
        auto customN = reinterpret_cast<CustomJSONData::v2::CustomBeatmapSaveData_NoteData *>(n);

        if (n->type == BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::NoteType::Bomb) {
            auto newNote = CustomBeatmapSaveData_BombNoteData::New_ctor(n->time,
                                                                        n->lineIndex,
                                                                        (int) n->lineLayer);
            newNote->customData = CustomJSONData::JSONWrapperOrNull(customN->customData);

            bombNotes.push_back(newNote);
        } else {
            auto newNote = CustomBeatmapSaveData_ColorNoteData::New_ctor(n->time,
                                                                         n->lineIndex,
                                                                         (int) n->lineLayer,
                                                                         GetNoteColorType(n->type),
                                                                         n->cutDirection,
                                                                         0);
            newNote->customData = CustomJSONData::JSONWrapperOrNull(customN->customData);
            colorNotes.push_back(newNote);
        }
    }
    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converted {} notes and {} bombs", colorNotes.size(), bombNotes.size());


    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting obstacles");
    for (auto const &n: VList(beatmap->obstacles)) {
        auto customN = reinterpret_cast<CustomJSONData::v2::CustomBeatmapSaveData_ObstacleData *>(n);

        auto obstacle = CustomBeatmapSaveData_ObstacleData::New_ctor(
                n->time,
                n->lineIndex,
                GetLayerForObstacleType(n->type),
                n->duration,
                n->width,
                GetHeightForObstacleType(n->type));

        obstacle->customData = CustomJSONData::JSONWrapperOrNull(customN->customData);

        obstacles.push_back(obstacle);
    }

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting Sliders");
    for (auto const &n: VList(beatmap->sliders)) {
        auto customN = reinterpret_cast<CustomJSONData::v2::CustomBeatmapSaveData_SliderData *>(n);

        auto slider = CustomBeatmapSaveData_SliderData::New_ctor(
                GetNoteColorType(n->colorType),
                n->headTime,
                n->headLineIndex,
                (int) n->headLineLayer,
                n->headControlPointLengthMultiplier,
                n->headCutDirection,
                n->tailTime,
                n->tailLineIndex,
                (int) n->tailLineLayer,
                n->tailControlPointLengthMultiplier,
                n->tailCutDirection,
                n->sliderMidAnchorMode);

        slider->customData = CustomJSONData::JSONWrapperOrNull(customN->customData);

        sliders.push_back(slider);
    }

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting waypoints");
    for (auto const &n: VList(beatmap->waypoints)) {
        auto customN = reinterpret_cast<CustomJSONData::v2::CustomBeatmapSaveData_ObstacleData *>(n);

        auto waypoint = CustomJSONData::NewFast<WaypointData *>(
                n->time,
                n->lineIndex,
                (int) n->lineLayer,
                n->offsetDirection);

        waypoints.push_back(waypoint);
    }

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting events");
    for (auto const &n: VList(beatmap->events)) {
        auto customN = reinterpret_cast<CustomJSONData::v2::CustomBeatmapSaveData_EventData *>(n);

        switch (customN->type) {
            case BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType::Event5: {
                auto boost = CustomJSONData::NewFast<ColorBoostEventData *>(n->time, n->value == 1);
                // TODO: Custom data
                colorBoosts.push_back(boost);
                continue;
            }
            case BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType::Event14:
            case BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType::Event15: {
                auto rotation = CustomJSONData::NewFast<RotationEventData *>(n->time,
                                                                             n->type ==
                                                                             BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType::Event14
                                                                             ? BeatmapSaveData::ExecutionTime::Early
                                                                             : BeatmapSaveData::ExecutionTime::Late,
                                                                             SpawnRotationForEventValue(n->value));
                // TODO: Custom data
                rotationEvents.push_back(rotation);
                continue;
            }
            case BeatmapSaveDataVersion2_6_0AndEarlier::BeatmapSaveData::BeatmapEventType::BpmChange:
                // TODO: Custom data!
                bpmChanges.push_back(CustomJSONData::NewFast<BpmChangeEventData *>(n->time, n->floatValue));
                continue;
            default:
                auto event = v3::CustomBeatmapSaveData_BasicEventData::New_ctor(n->time, n->type, n->value,
                                                                                n->floatValue);
                event->customData = customN->customData;
                basicEvents.push_back(event);
                continue;
        }
    }

    auto keywordsInnerList = System::Collections::Generic::List_1<BeatmapSaveData::BasicEventTypesWithKeywords::BasicEventTypesForKeyword *>::New_ctor(
            beatmap->specialEventsKeywordFilters->keywords->get_Count());
    VList<BeatmapSaveDataVersion3::BeatmapSaveData::BasicEventTypesWithKeywords::BasicEventTypesForKeyword *> keywords(
            keywordsInnerList);
    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Converting specialEventsKeywordFilters {} with size {}",
                                            fmt::ptr(keywordsInnerList), keywords.size());

    for (auto const &n: VList(beatmap->specialEventsKeywordFilters->keywords)) {
        keywords.push_back(
                CustomJSONData::NewFast<BeatmapSaveData::BasicEventTypesWithKeywords::BasicEventTypesForKeyword *>(
                        n->keyword, n->specialEvents));
    }

    auto basicEventTypesWithKeywords =
            CustomJSONData::NewFast<BeatmapSaveData::BasicEventTypesWithKeywords *>(keywordsInnerList);

    colorNotes.trim();
    bombNotes.trim();

    auto v3beatmap = CustomBeatmapSaveData::New_ctor(*bpmChanges,
                                                     *rotationEvents,
                                                     *colorNotes,
                                                     *bombNotes,
                                                     *obstacles,
                                                     *sliders,
                                                     *VList<BeatmapSaveData::BurstSliderData *>(),
                                                     *waypoints,
                                                     *basicEvents,
                                                     *colorBoosts,
                                                     *VList<BeatmapSaveData::LightColorEventBoxGroup *>(),
                                                     *VList<BeatmapSaveData::LightRotationEventBoxGroup *>(),
                                                     *VList<BeatmapSaveData::LightTranslationEventBoxGroup *>(),
                                                     basicEventTypesWithKeywords,
                                                     true);

    v3beatmap->customEventsData = beatmap->customEventsData;
    v3beatmap->doc = beatmap->doc;
    v3beatmap->customData = beatmap->customData;

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("beatmap eventkeywords {} vs our {} and finally items {}",
                                            fmt::ptr(v3beatmap->basicEventTypesWithKeywords->d),
                                            fmt::ptr(basicEventTypesWithKeywords->d),
                                            fmt::ptr(basicEventTypesWithKeywords->d->items.convert()));

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("Finished converting 2.0.0 to 3.0.0 map");
    auto stopTime = std::chrono::high_resolution_clock::now();

    CJDLogger::Logger.fmtLog<LogLevel::DBG>("This took {}ms",
                                            (int) std::chrono::duration_cast<std::chrono::milliseconds>(
                                                    stopTime - startTime).count());

    return v3beatmap;
}
