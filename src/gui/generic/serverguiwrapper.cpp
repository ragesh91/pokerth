/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "serverguiwrapper.h"
#include <session.h>


using namespace std;


ServerGuiWrapper::ServerGuiWrapper(ConfigFile *config, ClientCallback *clientcb, ServerCallback *servercb, IrcCallback *irccb)
: myConfig(config), myClientcb(clientcb), myServercb(servercb), myIrccb(irccb)
{
}

ServerGuiWrapper::~ServerGuiWrapper()
{
}

void ServerGuiWrapper::initGui(int /*speed*/) {}

Session &ServerGuiWrapper::getSession()
{
	assert(mySession.get());
	return *mySession;
}

void ServerGuiWrapper::setSession(boost::shared_ptr<Session> session)
{
	mySession = session;
}

void ServerGuiWrapper::refreshSet() const {}

void ServerGuiWrapper::refreshCash() const {}

void ServerGuiWrapper::refreshAction(int /*playerID*/, int /*playerAction*/) const {}

void ServerGuiWrapper::refreshChangePlayer() const {}

void ServerGuiWrapper::refreshAll() const {}

void ServerGuiWrapper::refreshPot() const {}
void ServerGuiWrapper::refreshGroupbox(int /*playerID*/, int /*status*/) const {}
void ServerGuiWrapper::refreshPlayerName() const {}
void ServerGuiWrapper::refreshButton() const {}
void ServerGuiWrapper::refreshGameLabels(GameState /*state*/) const {}

void ServerGuiWrapper::waitForGuiUpdateDone() const {}

void ServerGuiWrapper::dealBeRoCards(int /*myBeRoID*/) {}
void ServerGuiWrapper::dealHoleCards() {}
void ServerGuiWrapper::dealFlopCards() {}
void ServerGuiWrapper::dealTurnCard() {}
void ServerGuiWrapper::dealRiverCard() {}

void ServerGuiWrapper::nextPlayerAnimation() {}

void ServerGuiWrapper::beRoAnimation2(int /*myBeRoID*/) {}

void ServerGuiWrapper::preflopAnimation1() {}
void ServerGuiWrapper::preflopAnimation2() {}

void ServerGuiWrapper::flopAnimation1() {}
void ServerGuiWrapper::flopAnimation2() {}

void ServerGuiWrapper::turnAnimation1() {}
void ServerGuiWrapper::turnAnimation2() {}

void ServerGuiWrapper::riverAnimation1() {}
void ServerGuiWrapper::riverAnimation2() {}

void ServerGuiWrapper::postRiverAnimation1() {}
void ServerGuiWrapper::postRiverRunAnimation1() {}

void ServerGuiWrapper::flipHolecardsAllIn() {}

void ServerGuiWrapper::nextRoundCleanGui() {}

void ServerGuiWrapper::meInAction() {}
void ServerGuiWrapper::disableMyButtons() {}
void ServerGuiWrapper::startTimeoutAnimation(int /*playerId*/, int /*timeoutSec*/) {}
void ServerGuiWrapper::stopTimeoutAnimation(int /*playerId*/) {}

void ServerGuiWrapper::logPlayerActionMsg(string /*playerName*/, int /*action*/, int /*setValue*/) {}
void ServerGuiWrapper::logNewGameHandMsg(int /*gameID*/, int /*handID*/) {}
void ServerGuiWrapper::logPlayerWinsMsg(std::string /*playerName*/, int /*pot*/) {}
void ServerGuiWrapper::logNewBlindsSetsMsg(int /*sbSet*/, int /*bbSet*/, std::string /*sbName*/, std::string /*bbName*/) {}
	
void ServerGuiWrapper::logDealBoardCardsMsg(int /*roundID*/, int /*card1*/, int /*card2*/, int /*card3*/, int /*card4*/, int /*card5*/) {}
void ServerGuiWrapper::logFlipHoleCardsMsg(std::string /*playerName*/, int /*card1*/, int /*card2*/, int /*cardsValueInt*/, std::string /*showHas*/) {}
void ServerGuiWrapper::logPlayerWinGame(std::string /*playerName*/, int /*gameID*/) {}
void ServerGuiWrapper::flushLogAtGame(int /*gameID*/) {}
void ServerGuiWrapper::flushLogAtHand() {}

void ServerGuiWrapper::SignalNetClientConnect(int actionID) { if (myClientcb) myClientcb->SignalNetClientConnect(actionID); }
void ServerGuiWrapper::SignalNetClientGameInfo(int actionID) { if (myClientcb) myClientcb->SignalNetClientGameInfo(actionID); }
void ServerGuiWrapper::SignalNetClientError(int errorID, int osErrorID) { if (myClientcb) myClientcb->SignalNetClientError(errorID, osErrorID); }
void ServerGuiWrapper::SignalNetClientNotification(int notificationId) { if (myClientcb) myClientcb->SignalNetClientNotification(notificationId); }
void ServerGuiWrapper::SignalNetClientRemovedFromGame(int notificationId) { if (myClientcb) myClientcb->SignalNetClientRemovedFromGame(notificationId); }
void ServerGuiWrapper::SignalNetClientSelfJoined(unsigned playerId, const string &playerName, PlayerRights rights) { if (myClientcb) myClientcb->SignalNetClientSelfJoined(playerId, playerName, rights); }
void ServerGuiWrapper::SignalNetClientPlayerJoined(unsigned playerId, const string &playerName, PlayerRights rights) { if (myClientcb) myClientcb->SignalNetClientPlayerJoined(playerId, playerName, rights); }
void ServerGuiWrapper::SignalNetClientPlayerChanged(unsigned playerId, const string &newPlayerName) { if (myClientcb) myClientcb->SignalNetClientPlayerChanged(playerId, newPlayerName); }
void ServerGuiWrapper::SignalNetClientPlayerLeft(unsigned playerId, const string &playerName) { if (myClientcb) myClientcb->SignalNetClientPlayerLeft(playerId, playerName); }
void ServerGuiWrapper::SignalNetClientNewGameAdmin(unsigned playerId, const string &playerName) { if (myClientcb) myClientcb->SignalNetClientNewGameAdmin(playerId, playerName); }
void ServerGuiWrapper::SignalNetClientGameListNew(unsigned gameId) { if (myClientcb) myClientcb->SignalNetClientGameListNew(gameId); }
void ServerGuiWrapper::SignalNetClientGameListRemove(unsigned gameId) { if (myClientcb) myClientcb->SignalNetClientGameListRemove(gameId); }
void ServerGuiWrapper::SignalNetClientGameListUpdateMode(unsigned gameId, GameMode mode) { if (myClientcb) myClientcb->SignalNetClientGameListUpdateMode(gameId, mode); }
void ServerGuiWrapper::SignalNetClientGameListPlayerJoined(unsigned gameId, unsigned playerId) { if (myClientcb) myClientcb->SignalNetClientGameListPlayerJoined(gameId, playerId); }
void ServerGuiWrapper::SignalNetClientGameListPlayerLeft(unsigned gameId, unsigned playerId) { if (myClientcb) myClientcb->SignalNetClientGameListPlayerLeft(gameId, playerId); }
void ServerGuiWrapper::SignalNetClientGameStart(boost::shared_ptr<Game> game) { if (myClientcb) myClientcb->SignalNetClientGameStart(game); }
void ServerGuiWrapper::SignalNetClientChatMsg(const string &playerName, const string &msg) { if (myClientcb) myClientcb->SignalNetClientChatMsg(playerName, msg); }
void ServerGuiWrapper::SignalNetClientWaitDialog() { if (myClientcb) myClientcb->SignalNetClientWaitDialog(); }

void ServerGuiWrapper::SignalNetServerSuccess(int actionID) { if (myServercb) myServercb->SignalNetServerSuccess(actionID); }
void ServerGuiWrapper::SignalNetServerError(int errorID, int osErrorID) { if (myServercb) myServercb->SignalNetServerError(errorID, osErrorID); }

void ServerGuiWrapper::SignalIrcConnect(const string &server) { if (myIrccb) myIrccb->SignalIrcConnect(server); }
void ServerGuiWrapper::SignalIrcSelfJoined(const string &nickName, const std::string &channel) { if (myIrccb) myIrccb->SignalIrcSelfJoined(nickName, channel); }
void ServerGuiWrapper::SignalIrcPlayerJoined(const string &nickName) { if (myIrccb) myIrccb->SignalIrcPlayerJoined(nickName); }
void ServerGuiWrapper::SignalIrcPlayerChanged(const string &oldNick, const string &newNick) { if (myIrccb) myIrccb->SignalIrcPlayerChanged(oldNick, newNick); }
void ServerGuiWrapper::SignalIrcPlayerKicked(const string &nickName, const string &byWhom, const string &reason) { if (myIrccb) myIrccb->SignalIrcPlayerKicked(nickName, byWhom, reason); }
void ServerGuiWrapper::SignalIrcPlayerLeft(const string &nickName) { if (myIrccb) myIrccb->SignalIrcPlayerLeft(nickName); }
void ServerGuiWrapper::SignalIrcChatMsg(const string &nickName, const string &msg) { if (myIrccb) myIrccb->SignalIrcChatMsg(nickName, msg); }
void ServerGuiWrapper::SignalIrcError(int errorCode) { if (myIrccb) myIrccb->SignalIrcError(errorCode); }
void ServerGuiWrapper::SignalIrcServerError(int errorCode) {if (myIrccb) myIrccb->SignalIrcServerError(errorCode); }
