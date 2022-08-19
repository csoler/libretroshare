/*******************************************************************************
 * libretroshare/src/gxstunnel: p3gxsconnectedgroup.cc                         *
 *                                                                             *
 * libretroshare: retroshare core library                                      *
 *                                                                             *
 * Copyright 2008 by Robert Fernie <retroshare@lunamutt.com>                   *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Lesser General Public License as              *
 * published by the Free Software Foundation, either version 3 of the          *
 * License, or (at your option) any later version.                             *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
 * GNU Lesser General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Lesser General Public License    *
 * along with this program. If not, see <https://www.gnu.org/licenses/>.       *
 *                                                                             *
 *******************************************************************************/

// This class manages a group of distant GXS identities connected together using secured/authenticated tunnels.
// It is responsible for
// 	* keeping connections alive when needed (not all peers are connected)
//  * sending keep-alive packets between peers, or disconnecting them when needed
//
// It is not responsible for
//	* forwarding data between peers.
//
// Clients, who use the group for e.g. data distribution, will
//	* keep the group server posted about which peers are not available anymore
//

#include <map>

#include <retroshare/rsids.h>

using RsGxsConnectedGroupId = t_RsGenericIdType<_RsIdSize::SSL_ID, false, RsGenericIdType::GXS_TUNNEL>; // to be changed later

struct RsGxsConnectedGroupInfo
{
    std::list<RsGxsId> participants;
};

class p3GxsConnectedGroupServer
{
public:
    p3GxsConnectedGroupServer();

    bool createdGroup(RsGxsConnectedGroupId& gid);

    bool getGroupStatistics(std::map<RsGxsConnectedGroupId,RsGxsConnectedGroupInfo>& infos) const;

protected:
    virtual void tick();
};

// Maintains a chat group, based on the algorithm that forwards data between distant peers

class p3GxsChatGroup //: public p3GxsConnectedGroupServer, DistantChatBouncer
{
public:
    p3GxsChatGroup();
};


