//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace TunesPP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	this->catList = ref new CATEGORY_LIST();
	this->trackList = ref new UBERSNIP_TRACKLIST();

	UBERSNIP_TRACK^ track1 = ref new UBERSNIP_TRACK();
	track1->Artist = "K. Bust";
	track1->SetImage("Assets/kbustwall.jpg");
	
	UBERSNIP_TRACK^ track2 = ref new UBERSNIP_TRACK();
	track2->Artist = "LorDiddy";
	track2->SetImage("Assets/lordiddywall.jpg");

	UBERSNIP_TRACK^ track3 = ref new UBERSNIP_TRACK();
	track3->Artist = "JulesM";
	track3->SetImage("Assets/julesmwall.jpg");

	UBERSNIP_TRACK^ track4 = ref new UBERSNIP_TRACK();
	track4->Artist = "Leftist";
	track4->SetImage("Assets/leftistwall.jpg");

	this->trackList->Tracks->Append(track1);
	this->trackList->Tracks->Append(track2);
	this->trackList->Tracks->Append(track3);
	this->trackList->Tracks->Append(track4);

	Platform::String^ Categories[] = { "Hip Hop", "Rap", "Pop", "Electric", "Country", "Business", "Politics" };

	for (size_t i = 0; i < (*Categories)->Length(); i++) {
		CATEGORY_ITEM^ catItem = ref new CATEGORY_ITEM();
		catItem->Title = Categories[i];
		this->catList->Items->Append(catItem);
	}
}
