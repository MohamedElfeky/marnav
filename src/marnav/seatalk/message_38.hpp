#ifndef __SEATALK__MESSAGE_38__HPP__
#define __SEATALK__MESSAGE_38__HPP__

#include "message.hpp"

namespace marnav
{
namespace seatalk
{

/// @brief Codelock data
///
/// @code
/// 38 X1 YY yy
/// @endcode
///
/// @todo Implement data of this message
///
class message_38 : public message
{
public:
	constexpr static const message_id ID = message_id::codelock_data;

	message_38();
	message_38(const message_38 &) = default;
	message_38 & operator=(const message_38 &) = default;

	virtual raw get_data() const override;

	static std::unique_ptr<message> parse(const raw & data) throw(std::invalid_argument);
};
}
}

#endif
