#pragma once
#ifndef INFODATAFIXTURE_H__
#define INFODATAFIXTURE_H__
/////////////////////////////////
#include <mydefs.h>
//////////////////////////////
namespace infoged
{
	///////////////////////////////
	namespace test
	{
		/////////////////////////////
		class fixture
		{
		public:
			fixture();
			fixture(const fixture &other);
			fixture &operator=(const fixture &other);
			virtual ~fixture();
		public:
			string get_test_base_dir(void) const;
			string get_jpeg_filename(void) const;
			string get_mp4_filename(void) const;
			string get_medias_folder(void) const;
			string get_test_ged_filename(void) const;
			string get_test_result_ged_filename(void) const;
			string get_test_temp_ged_filename(void) const;
			string get_genea_media_dir(void) const;
			//
			string create_random_string(size_t nlength = 31) const;
			//
		}; // class fixture
	} // test
} // mat
////////////////////////////////
#endif // INFODATAFIXTURE_H__
