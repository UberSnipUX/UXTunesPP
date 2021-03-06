﻿//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;

namespace TunesPP
{

	[Windows::UI::Xaml::Data::Bindable]
	public ref class UBERSNIP_TRACK sealed {
	private:
		Platform::String^ _ID;
		Platform::String^ _uid;
		Platform::String^ _artist;
		Platform::String^ _album;
		Platform::String^ _title;
		Platform::String^ _description;
		Platform::String^ _filename;
		Platform::String^ _views;
		Platform::String^ _likes;
		Platform::String^ _genre;
		Windows::UI::Xaml::Media::ImageSource^ _Image;

		event PropertyChangedEventHandler^ _PropertyChanged;

		void OnPropertyChanged(Platform::String^ propertyName)
		{
			PropertyChangedEventArgs^ pcea = ref new  PropertyChangedEventArgs(propertyName);
			_PropertyChanged(this, pcea);
		}
	public:
		UBERSNIP_TRACK() {

		};

		property Platform::String^ ID {
			Platform::String^ get() {
				return this->_ID;
			}

			void set(Platform::String^ val) {
				this->_ID = val;
			}
		}

		property Platform::String^ UID {
			Platform::String^ get() {
				return this->_uid;
			}

			void set(Platform::String^ val) {
				this->_uid = val;
			}
		}

		property Platform::String^ Artist {
			Platform::String^ get() {
				return this->_artist;
			}

			void set(Platform::String^ val) {
				this->_artist = val;
			}
		}

		property Platform::String^ Album {
			Platform::String^ get() {
				return this->_album;
			}

			void set(Platform::String^ val) {
				this->_album = val;
			}
		}

		property Platform::String^ Genre {
			Platform::String^ get() {
				return this->_genre;
			}

			void set(Platform::String^ val) {
				this->_genre = val;
			}
		}


		property Platform::String^ Title {
			Platform::String^ get() {
				return this->_title;
			}

			void set(Platform::String^ val) {
				this->_title = val;
			}
		}


		property Platform::String^ Description {
			Platform::String^ get() {
				return this->_description;
			}

			void set(Platform::String^ val) {
				this->_description = val;
			}
		}


		property Platform::String^ FileName {
			Platform::String^ get() {
				return this->_filename;
			}

			void set(Platform::String^ val) {
				this->_filename = val;
			}
		}


		property Platform::String^ Views {
			Platform::String^ get() {
				return this->_views;
			}

			void set(Platform::String^ val) {
				this->_views = val;
			}
		}


		property Platform::String^ Likes {
			Platform::String^ get() {
				return this->_likes;
			}

			void set(Platform::String^ val) {
				this->_likes = val;
			}
		}

		//Image
		property Windows::UI::Xaml::Media::ImageSource^ Image
		{
			Windows::UI::Xaml::Media::ImageSource^ get()
			{
				return _Image;
			}
			void set(Windows::UI::Xaml::Media::ImageSource^ value)
			{
				_Image = value;
				OnPropertyChanged("Image");
			}
		}

		void SetImage(Platform::String^ path)
		{
			Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri("ms-appx://TunesPP/" + path);
			_Image = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
		}

	};

	[Windows::Foundation::Metadata::WebHostHiddenAttribute]
	public ref class UBERSNIP_TRACKLIST sealed {
	private:
		Windows::UI::Xaml::Interop::IBindableObservableVector^ tracks;

	public:
		UBERSNIP_TRACKLIST() {
			tracks = ref new Platform::Collections::Vector<UBERSNIP_TRACK^>();
		}

		property Windows::UI::Xaml::Interop::IBindableObservableVector^ Tracks {
			Windows::UI::Xaml::Interop::IBindableObservableVector^ get() {
				return this->tracks;
			}
		}
	};

	[Windows::UI::Xaml::Data::Bindable]
	public ref class CATEGORY_ITEM sealed {
	private:
		Platform::String^ _title;
		Windows::UI::Xaml::Media::ImageSource^ _Image;

		event PropertyChangedEventHandler^ _PropertyChanged;

		void OnPropertyChanged(Platform::String^ propertyName)
		{
			PropertyChangedEventArgs^ pcea = ref new  PropertyChangedEventArgs(propertyName);
			_PropertyChanged(this, pcea);
		}
	public:
		CATEGORY_ITEM() {

		};

		property Platform::String^ Title {
			Platform::String^ get() {
				return this->_title;
			}

			void set(Platform::String^ val) {
				this->_title = val;
				OnPropertyChanged("Title");
			}
		}

		void SetImage(Platform::String^ path)
		{
			Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri(path);
			_Image = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
		}

	};

	[Windows::Foundation::Metadata::WebHostHiddenAttribute]
	public ref class CATEGORY_LIST sealed {
	private:
		Windows::UI::Xaml::Interop::IBindableObservableVector^ items;

	public:
		CATEGORY_LIST() {
			items = ref new Platform::Collections::Vector<CATEGORY_ITEM^>();
		}

		property Windows::UI::Xaml::Interop::IBindableObservableVector^ Items {
			Windows::UI::Xaml::Interop::IBindableObservableVector^ get() {
				return this->items;
			}
		}
	};

	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
		CATEGORY_LIST^ catList;
		UBERSNIP_TRACKLIST^ trackList;
	public:
		MainPage();

		property CATEGORY_LIST^ CategoryList
		{
			CATEGORY_LIST^ get() { return this->catList; };
		}


		property UBERSNIP_TRACKLIST^ TrackList
		{
			UBERSNIP_TRACKLIST^ get() { return this->trackList; };
		}
	};
}
