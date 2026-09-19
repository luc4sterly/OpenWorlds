// 1001c600 FUN_1001c600 [Global]
// programa: RWL21.DLL

undefined8 __fastcall FUN_1001c600(undefined4 param_1,undefined4 param_2,float *param_3)

{
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar1;
  float local_c [3];
  
  if (*(char *)(param_3 + 0x10) != '\0') {
    return CONCAT44(param_2,CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_3 + 0x10)));
  }
  RwCrossProduct(param_3,param_3 + 4,local_c);
  uVar1 = RwDotProduct(extraout_ECX,extraout_EDX);
  return uVar1;
}


