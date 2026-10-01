// 1000ba40 RwGetCameraLTM [Global]
// program: RWL21.DLL

undefined4 * __fastcall
RwGetCameraLTM(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
                    /* 0xba40  133  RwGetCameraLTM */
  if ((param_3 != 0) && (param_4 != (undefined4 *)0x0)) {
    puVar1 = FUN_1001d020(param_1,param_2,(undefined4 *)(param_3 + 4),param_4);
    return puVar1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


