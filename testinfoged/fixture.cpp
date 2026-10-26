#include "fixture.h"
///////////////////////////
#include <random>
////////////////////////
namespace infoged
{
	namespace test
	{
		/////////////////////////////////////
		fixture::fixture()
		{
		}
		fixture::~fixture()
		{
		}
		fixture::fixture(const fixture & /*other*/)
		{
		}
		fixture &fixture::operator=(const fixture & /*other*/)
		{
			return *this;
		}
		string fixture::create_random_string(size_t nlength) const
		{
			const string characters =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";

			// Random device and generator
			std::random_device rd;		  // Non-deterministic seed
			std::mt19937 generator(rd()); // Mersenne Twister engine
			std::uniform_int_distribution<> distribution(0, static_cast<int>(characters.size() - 1));

			std::string randomString;
			randomString.reserve(nlength);

			for (std::size_t i = 0; i < nlength; ++i)
			{
				randomString += characters[distribution(generator)];
			}

			return randomString;
		}
		string fixture::get_test_ged_filename(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/test.ged");
#else
			return string("C:\\testdata\\test.ged");
#endif
		}
		string fixture::get_test_result_ged_filename(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/test_result.ged");
#else
			return string("C:\\testdata\\test_result.ged");
#endif
		}
		string fixture::get_test_temp_ged_filename(void) const
		{

#if defined(__linux__)
			return string("/home/boubad/testdata/test_temp.ged");
#else
			return string("C:\\testdata\\test_temp.ged");
#endif
		}
		string fixture::get_test_base_dir(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/");
#else
			return string("C:\\testdata\\");
#endif
		}
		string fixture::get_jpeg_filename(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/test.jpg");
#else
			return string("C:\\testdata\\test.jpg");
#endif
		}
		string fixture::get_mp4_filename(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/test.mp4");
#else
			return string("C:\\testdata\\test.mp4");
#endif
		}
		string fixture::get_medias_folder(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/testdata/medias/");
#else
			return string("C:\\testdata\\medias\\");
#endif
		}
		string fixture::get_genea_media_dir(void) const
		{
#if defined(__linux__)
			return string("/home/boubad/genea/media/");
#else
			return string("C:\\genea\\media\\");
#endif
		}
		/////////////////////////////////////////
	} // test
} // infoged
