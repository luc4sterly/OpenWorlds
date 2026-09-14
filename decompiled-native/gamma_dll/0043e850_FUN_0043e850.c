// 0043e850 FUN_0043e850 [Global]
// programa: gamma.dll

void __thiscall FUN_0043e850(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *local_10;
  
  puVar1 = *(undefined4 **)((int)this + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00466fe8,&local_10);
  if (iVar2 < 0) {
    return;
  }
  if (param_1 == 0) {
    uVar4 = *(undefined4 *)((int)this + 0x1c);
    iVar2 = 0;
    uVar3 = 0xfffffffd;
  }
  else {
    (**(code **)(*local_10 + 0x2c))
              (local_10,0xfffffffb,0,this,0,*(undefined4 *)((int)this + 0x1c),(int)this + 0x28);
    uVar4 = *(undefined4 *)((int)this + 0x1c);
    iVar2 = (int)this + 0x28;
    uVar3 = 0xffffffff;
  }
  (**(code **)(*local_10 + 0x2c))(local_10,uVar3,0,this,0,uVar4,iVar2);
  (**(code **)(*local_10 + 8))(local_10);
  return;
}


