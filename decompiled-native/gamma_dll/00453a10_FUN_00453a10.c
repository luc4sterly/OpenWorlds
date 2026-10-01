// 00453a10 FUN_00453a10 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00453a10(void *this,int param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  FUN_00453a60(this,param_1,(undefined4 *)&DAT_00481ee8);
  FUN_00453820((void *)((int)this + 0xc),&DAT_00481370);
  return this;
}


