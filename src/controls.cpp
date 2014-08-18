/***********************************************************************
     * File       : controls.cpp
     * Created    : Aug 18, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * DemoControls
     * init

***********************************************************************/
void DemoControls::init(DemoState *state) {
	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);
	box->SetPosition(sf::Vector2f(800, 10));
	box->Pack(sfg::Label::Create("Welcome to"), false);
	box->Pack(sfg::Label::Create("Colorful Lighting Demo"), false);
	box->Pack(sfg::Label::Create("by Achpile\n\n"), false);

	auto button = sfg::Button::Create("Clear");
	button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&clearSources));
	box->Pack(button);


	box->Pack(sfg::Label::Create("\n_________________________________\n\n"), false);


	auto ambientIntensity = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	ambIntensityAdj       = ambientIntensity->GetAdjustment();

	ambIntensityAdj->SetMinorStep(1.f);
	ambIntensityAdj->SetMajorStep(3.f);
	ambIntensityAdj->SetLower(0);
	ambIntensityAdj->SetUpper(LIGHT_MAX_LIGHTLEVEL);
	ambIntensityAdj->SetValue(state->ambientIntensity);
	ambientIntensity->SetRequisition(sf::Vector2f(180.f, 20.f));

	box->Pack(sfg::Label::Create("Ambient intensity"), false);
	box->Pack(ambientIntensity);
	box->Pack(sfg::Label::Create("\n"), false);


	auto ambientColR = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	auto ambientColG = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	auto ambientColB = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	ambColR          = ambientColR->GetAdjustment();
	ambColG          = ambientColG->GetAdjustment();
	ambColB          = ambientColB->GetAdjustment();

	ambColR->SetMinorStep(1.f);
	ambColR->SetMajorStep(15.f);
	ambColR->SetLower(0);
	ambColR->SetUpper(255);
	ambColR->SetValue(state->ambientColor.r);
	ambientColR->SetRequisition(sf::Vector2f(180.f, 20.f));

	ambColG->SetMinorStep(1.f);
	ambColG->SetMajorStep(15.f);
	ambColG->SetLower(0);
	ambColG->SetUpper(255);
	ambColG->SetValue(state->ambientColor.g);
	ambientColG->SetRequisition(sf::Vector2f(180.f, 20.f));

	ambColB->SetMinorStep(1.f);
	ambColB->SetMajorStep(15.f);
	ambColB->SetLower(0);
	ambColB->SetUpper(255);
	ambColB->SetValue(state->ambientColor.b);
	ambientColB->SetRequisition(sf::Vector2f(180.f, 20.f));

	box->Pack(sfg::Label::Create("Ambient color"), false);
	box->Pack(ambientColR);
	box->Pack(ambientColG);
	box->Pack(ambientColB);


	box->Pack(sfg::Label::Create("\n_________________________________\n\n"), false);


	auto brushIntensity = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	brIntensityAdj       = brushIntensity->GetAdjustment();

	brIntensityAdj->SetMinorStep(1.f);
	brIntensityAdj->SetMajorStep(3.f);
	brIntensityAdj->SetLower(0);
	brIntensityAdj->SetUpper(LIGHT_MAX_LIGHTLEVEL);
	brIntensityAdj->SetValue(state->brush.intensity);
	brushIntensity->SetRequisition(sf::Vector2f(180.f, 20.f));

	box->Pack(sfg::Label::Create("Brush intensity"), false);
	box->Pack(brushIntensity);
	box->Pack(sfg::Label::Create("\n"), false);


	auto brushColR = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	auto brushColG = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	auto brushColB = sfg::Scale::Create(sfg::Scale::Orientation::HORIZONTAL);
	brColR          = brushColR->GetAdjustment();
	brColG          = brushColG->GetAdjustment();
	brColB          = brushColB->GetAdjustment();

	brColR->SetMinorStep(1.f);
	brColR->SetMajorStep(15.f);
	brColR->SetLower(0);
	brColR->SetUpper(255);
	brColR->SetValue(state->brush.color.r);
	brushColR->SetRequisition(sf::Vector2f(180.f, 20.f));

	brColG->SetMinorStep(1.f);
	brColG->SetMajorStep(15.f);
	brColG->SetLower(0);
	brColG->SetUpper(255);
	brColG->SetValue(state->brush.color.g);
	brushColG->SetRequisition(sf::Vector2f(180.f, 20.f));

	brColB->SetMinorStep(1.f);
	brColB->SetMajorStep(15.f);
	brColB->SetLower(0);
	brColB->SetUpper(255);
	brColB->SetValue(state->brush.color.b);
	brushColB->SetRequisition(sf::Vector2f(180.f, 20.f));

	box->Pack(sfg::Label::Create("Brush color"), false);
	box->Pack(brushColR);
	box->Pack(brushColG);
	box->Pack(brushColB);

	brStyle = sfg::ComboBox::Create();
	brStyle->AppendItem("Static");
	brStyle->AppendItem("Fading");
	brStyle->AppendItem("Pulsing");
	brStyle->SelectItem(0);
	box->Pack(brStyle);

	box->Pack(sfg::Label::Create("Source time"), false);
	brTime = sfg::SpinButton::Create(0.0f, 20.0f, 0.1f);
	brTime->SetRequisition(sf::Vector2f(80.f, 0.f));
	brTime->SetDigits(2);
	brTime->SetValue(state->brush.sourceTime);
	box->Pack(brTime);

	desktop.Add(box);
}



/***********************************************************************
     * DemoControls
     * render

***********************************************************************/
void DemoControls::render() {
	app->resetGLStates();
	sfgui.Display( *app );
}



/***********************************************************************
     * DemoControls
     * update

***********************************************************************/
void DemoControls::update() {
	desktop.Update(frameClock);
}
