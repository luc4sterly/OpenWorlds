// 0043e5e0 FUN_0043e5e0 [Global]
// programa: gamma.dll

undefined4 FUN_0043e5e0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uStack_10;
  
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  (**(code **)*puVar1)(puVar1,&DAT_00466f78,&uStack_10);
  *param_2 = uStack_10;
  return 0;
}


