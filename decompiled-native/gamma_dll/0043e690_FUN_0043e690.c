// 0043e690 FUN_0043e690 [Global]
// programa: gamma.dll

void __fastcall FUN_0043e690(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14;
  int *local_10;
  
  CoCreateInstance((IID *)&stack0x00000004,(LPUNKNOWN)0x0,5,(IID *)&DAT_00466e40,
                   (LPVOID *)(param_1 + 0x24));
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00466fe8,&local_14);
  if (iVar2 < 0) {
    return;
  }
  (**(code **)(*local_14 + 0xc))(local_14,param_1);
  (**(code **)(*local_14 + 8))(local_14);
  iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x24))
                    (*(undefined4 **)(param_1 + 0x24),&DAT_00467008,&local_10);
  if (-1 < iVar2) {
    (**(code **)(*local_10 + 0x20))(local_10);
    (**(code **)(*local_10 + 8))(local_10);
  }
  return;
}


