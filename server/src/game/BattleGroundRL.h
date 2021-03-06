/*
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __BATTLEGROUNDRL_H
#define __BATTLEGROUNDRL_H

#include "BattleGround.h"
#include "battlefield_specification.h"

class BattleGroundRLScore : public BattleGroundScore
{
public:
    BattleGroundRLScore(){};
    virtual ~BattleGroundRLScore(){};
    // TODO fix me
};

class BattleGroundRL : public BattleGround
{
    friend class BattleGroundMgr;

public:
    BattleGroundRL(const battlefield::specification& spec);
    ~BattleGroundRL();
    void Update(uint32 diff) override;

    /* inherited from BattlegroundClass */
    virtual void AddPlayer(Player* plr) override;
    virtual void FillInitialWorldStates(WorldPacket& d, uint32& count) override;
    virtual void StartingEventCloseDoors() override;
    virtual void StartingEventOpenDoors() override;

    void RemovePlayer(Player* plr, ObjectGuid guid) override;
    void HandleAreaTrigger(Player* Source, uint32 Trigger) override;
    bool SetupBattleGround() override;
    void HandleKillPlayer(Player* player, Player* killer) override;
    bool HandlePlayerUnderMap(Player* plr) override;

    battlefield::specification get_specification() const override
    {
        return specification_;
    }

private:
    battlefield::specification specification_;

    uint32 end_cond_check_timer_;
};
#endif
