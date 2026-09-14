// 004517c0 FUN_004517c0 [Global]
// programa: gamma.dll

undefined * FUN_004517c0(void)

{
  undefined4 local_40 [14];
  
  if (DAT_0049e550 == '\0') {
    FUN_00451840(local_40);
    FUN_004049e0(&DAT_0049e554,local_40);
    FUN_00450830(&DAT_0049e554,&LAB_00404980,(undefined4 *)&DAT_0049e544);
    FUN_00404dc0(local_40);
    DAT_0049e550 = '\x01';
  }
  return &DAT_0049e554;
}


