package NET.worlds.network;

public class P17UserServer extends UserServer {
   protected P17UserServer() {
      this._serverProtocolVersion = 17;
   }

   protected void state_XMIT_PROPREQ() {
      this._state.setState(7);
   }
}
