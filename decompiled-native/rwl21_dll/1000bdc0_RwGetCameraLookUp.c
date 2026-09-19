// 1000bdc0 RwGetCameraLookUp [Global]
// programa: RWL21.DLL

undefined4 RwGetCameraLookUp(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
                    /* 0xbdc0  136  RwGetCameraLookUp */
  if ((param_2 != (undefined4 *)0x0) && (param_1 != 0)) {
    uVar1 = FUN_1001cfd0(param_1 + 4,param_2);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


