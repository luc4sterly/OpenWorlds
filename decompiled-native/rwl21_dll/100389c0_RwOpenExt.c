// 100389c0 RwOpenExt [Global]
// programa: RWL21.DLL

undefined4 RwOpenExt(char *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int extraout_EAX;
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char local_104 [256];
  
                    /* 0x389c0  298  RwOpenExt */
  RwInitialize((int *)0x0);
  if ((extraout_EAX != 0) && (pcVar1 = RwGetDisplayDevices(), pcVar1 != (char *)0x0)) {
    iVar2 = RwFindDisplayDevice(pcVar1,(undefined4 *)0x0,param_1,param_2,param_3,(int)param_4);
    if (iVar2 == 0) {
      FUN_1000cba0(0x53);
    }
    else {
      RwExtract(pcVar1,iVar2,local_104,0x100);
      DAT_1005b750 = RwOpenDisplayDevice(local_104,param_1);
      if (DAT_1005b750 != (undefined *)0x0) {
        uVar3 = RwStartDisplayDeviceExt((int)DAT_1005b750,param_2,param_3,param_4);
        if (uVar3 != 0) {
          return 1;
        }
        return 0;
      }
    }
  }
  return 0;
}


