#pragma once

#include "../AuraGlobal.h"

#include <QRect>



//Qt 前置声明
class QPainter;

namespace AuraUI{
class Shadow;
class AuraProgressBar;
class AuraSwitchBtn;
class AuraCardLabel;
class AuraCardWidget;
class AuraCarouselWidget;
class AuraClassifyWidget;

using AuraProgressBarPaintFunction = void (*)(QPainter *,AuraProgressBar*);
using SwitchBarPaintFunction = void (*)(QPainter *,AuraSwitchBtn*);
using SwitchBarAnimationFunction = void(*)(AuraSwitchBtn*);
using CardLabelPaintFunction = void (*)(QPainter*,AuraCardLabel*);
using CardWidgetPaintFunction = void(*)(QPainter*,AuraCardWidget*);
using CardWidgetAnimationFunction  = void(*)(AuraCardWidget*);
using CarouselWidgetPaintFunction = void(*)(QPainter*,AuraCarouselWidget*);
using CarouselWidgetAnimationFunction = void(*)(AuraCarouselWidget*);
using ClassifyWidgetPaintFunction = void(*)(QPainter*,AuraClassifyWidget*);
using ClassifyWidgetLayoutFunction = void(*)(AuraClassifyWidget*);
//using CarouselDefaultRelayoutFunction
//=============================================================================
class AuraLibrary_DECL UIFunction
{
public:
    static void DrawDefaultProgressBar(QPainter * p,AuraProgressBar * obj);
    static void DrawFlowBallProgressBar(QPainter * p,AuraProgressBar * obj);

    static void DrawDefaultSwitchBtn(QPainter * p,AuraSwitchBtn* obj);

    static void AnimationDefaultSwitchBtnToOn(AuraSwitchBtn* obj);
    static void AnimationDefaultSwitchBtnToOff(AuraSwitchBtn* obj);

    static void DrawDefaultCardLabel(QPainter *p,AuraCardLabel* obj);
    static void DrawPixOnlyCardLabel(QPainter *p,AuraCardLabel* obj);

    //=====================================================card widget
    static void DrawDefaultCardWidget(QPainter *p,AuraCardWidget* obj);
    static void AnimationDefaultCardWidgetN2H(AuraCardWidget* obj);
    static void AnimationDefaultCardWidgetH2N(AuraCardWidget* obj);

    static void DrawClassifyCardWidget(QPainter *p,AuraCardWidget* obj);
    static void AnimationClassifyCardWidgetN2H(AuraCardWidget* obj);
    static void AnimationClassifyCardWidgetH2N(AuraCardWidget* obj);

    static void DrawStrenchCardWidget(QPainter *p,AuraCardWidget* obj);
    static void AnimationStrenchCardWidgetN2H(AuraCardWidget* obj);
    static void AnimationStrenchCardWidgetH2N(AuraCardWidget* obj);
    //=====================================================card widget


    //==================================================Carousel Widget
    static void DrawDefaultCarouselWidget(QPainter* p,AuraCarouselWidget* obj);
    static void DrawDefaultCarouselWidgetIndicator(QPainter* p,AuraCarouselWidget* obj);
    static void AnimationDefaultCarouselWidgetPreCard(AuraCarouselWidget* obj);
    static void AnimationDefaultCarouselWidgetNextCard(AuraCarouselWidget* obj);
    //==================================================Carousel Widget


    //========================================Classify Widget
    static void DrawDefaultClassifyWidget(QPainter* p ,AuraClassifyWidget* obj);
    static void LayoutDefaultClassifyWidget(AuraClassifyWidget* obj);
    //========================================Classify Widget


    //======================================================
    static void DrawShadow(QPainter* p,QRect wRect,Shadow shadow);
};

}//AuraUI
