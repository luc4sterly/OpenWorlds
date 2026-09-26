// 0041fc92 FUN_0041fc92 [Global]
// programa: sfmain.exe

void FUN_0041fc92(void)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined1 local_24;
  
  if (DAT_0046239c < *(uint *)(in_EAX + 8)) {
    FUN_004296b9(s__s__d_got_more_samples_than_expe_00436b06);
    FUN_004296b9(s_expected__d__got__d_00436b2e);
    *(uint *)(in_EAX + 8) = DAT_0046239c;
  }
  else if ((*(uint *)(in_EAX + 8) < DAT_0046239c) && (*(int *)(in_EAX + 8) != 0)) {
    FUN_004296b9(s__s__d_frame_shorter_than_expecte_00436b66);
    FUN_004296b9(s_frame_was__d_bytes__filled_out_t_00436b8b);
    if (DAT_0043d6a4 == 1) {
      local_24 = 0x80;
    }
    else {
      local_24 = 0;
    }
    FUN_00408098(extraout_ECX,local_24);
    *(uint *)(in_EAX + 8) = DAT_0046239c;
  }
  return;
}


