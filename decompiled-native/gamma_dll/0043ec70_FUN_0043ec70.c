// 0043ec70 FUN_0043ec70 [Global]
// program: gamma.dll

undefined4 FUN_0043ec70(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  (**(code **)*puVar1)(puVar1,&DAT_00466f78,&uStack_10);
  *param_2 = uStack_10;
  return 0;
}


