// 100319f0 RwGetClumpVertex [Global]
// program: RWL21.DLL

undefined4 * RwGetClumpVertex(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
                    /* 0x319f0  168  RwGetClumpVertex */
  if ((param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  if ((-8 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    puVar1 = (undefined4 *)FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    param_3[2] = puVar1[2];
    return param_3;
  }
  FUN_1000cba0(0x19);
  return (undefined4 *)0x0;
}


