#ifndef __NMEA__GLL__HPP__
#define __NMEA__GLL__HPP__

#include <marnav/nmea/sentence.hpp>
#include <marnav/nmea/angle.hpp>
#include <marnav/nmea/time.hpp>
#include <marnav/utils/optional.hpp>

namespace marnav
{
namespace nmea
{
MARNAV_NMEA_DECLARE_SENTENCE_PARSE_FUNC(gll)

/// @brief GLL - Geographic Position - Latitude/Longitude
///
/// @code
///        1       2 3        4 5         6 7
///        |       | |        | |         | |
/// $--GLL,llll.ll,a,yyyyy.yy,a,hhmmss.ss,a,m*hh<CR><LF>
/// @endcode
///
/// Field Number:
/// 1. Latitude
/// 2. Latitude hemipsphere
///    - N = North
///    - S = South
/// 3. Longitude
/// 4. Longitude hemisphere
///    - E = East
///    - W = West
/// 5. Time (UTC) of position
/// 6. Status
///    - A = Data Valid
///    - V = Data Invalid
/// 7. Mode indicator (only in newer versions)
///    - V = Invalid
///    - A = Autonomous
///    - D = Differential
///
class gll : public sentence
{
	MARNAV_NMEA_SENTENCE_FRIENDS(gll)

public:
	constexpr static const sentence_id ID = sentence_id::GLL;
	constexpr static const char * TAG = "GLL";

	virtual ~gll() {}

	gll();
	gll(const gll &) = default;
	gll & operator=(const gll &) = default;

protected:
	gll(const std::string & talker, fields::const_iterator first, fields::const_iterator last);
	virtual std::vector<std::string> get_data() const override;

private:
	utils::optional<geo::latitude> lat;
	utils::optional<direction> lat_hem;
	utils::optional<geo::longitude> lon;
	utils::optional<direction> lon_hem;
	utils::optional<nmea::time> time_utc;
	utils::optional<status> data_valid;
	utils::optional<positioning_system_mode_indicator> mode_indicator;

public:
	NMEA_GETTER(lat)
	NMEA_GETTER(lat_hem)
	NMEA_GETTER(lon)
	NMEA_GETTER(lon_hem)
	NMEA_GETTER(time_utc)
	NMEA_GETTER(data_valid)
	NMEA_GETTER(mode_indicator)

	void set_lat(const geo::latitude & t);
	void set_lon(const geo::longitude & t);
	void set_time_utc(const nmea::time & t) noexcept { time_utc = t; }
	void set_data_valid(status t) noexcept { data_valid = t; }
	void set_mode_indicator(positioning_system_mode_indicator t) noexcept
	{
		mode_indicator = t;
	}
};
}
}

#endif
