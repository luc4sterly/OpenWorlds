// 0042ae60 FUN_0042ae60 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042ae60(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_0042aff0(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    (**(code **)(*param_1 + 0x24))(s_out_of_dynamic_memory_in_yy_crea_00474350);
  }
  puVar1[3] = param_3;
  uVar2 = FUN_0042aff0(puVar1[3] + 2);
  puVar1[1] = uVar2;
  if (puVar1[1] == 0) {
    (**(code **)(*param_1 + 0x24))(s_out_of_dynamic_memory_in_yy_crea_00474350);
  }
  puVar1[5] = 1;
  FUN_0042af10(param_1,puVar1,param_2);
  return puVar1;
}


