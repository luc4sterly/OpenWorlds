// 004269c0 FUN_004269c0 [Global]
// program: gamma.dll

uint * __thiscall FUN_004269c0(void *this,byte *param_1,int param_2,char *param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char local_110 [256];
  
  uVar2 = FUN_00450b60(0x2ff);
  *(undefined4 *)this = uVar2;
  if (param_2 != 0) {
    uVar4 = *(uint *)this & 0xff;
    iVar5 = 0;
    if (uVar4 != 0) {
      iVar5 = 0x100 - uVar4;
    }
    *(uint *)((int)this + 4) = *(uint *)this + iVar5;
    if ((param_3 == (char *)0x0) || (param_4 == 0)) {
      iVar5 = 0;
      do {
        cVar1 = (char)iVar5;
        local_110[iVar5] = cVar1;
        local_110[iVar5 + 1] = cVar1 + '\x01';
        local_110[iVar5 + 2] = cVar1 + '\x02';
        local_110[iVar5 + 3] = cVar1 + '\x03';
        local_110[iVar5 + 4] = cVar1 + '\x04';
        local_110[iVar5 + 5] = cVar1 + '\x05';
        local_110[iVar5 + 6] = cVar1 + '\x06';
        iVar3 = iVar5 + 8;
        local_110[iVar5 + 7] = cVar1 + '\a';
        iVar5 = iVar3;
      } while (iVar3 < 0x100);
      param_4 = 0x100;
      param_3 = local_110;
    }
    iVar5 = FUN_00426930(param_1,param_2,(int)param_3,param_4,*(undefined1 **)((int)this + 4));
    if (iVar5 == 0) {
      FUN_00402800(s_huffdcod_00471cb0,0xd7);
    }
  }
  return this;
}


