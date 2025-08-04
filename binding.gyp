{
  "targets": [
    {
      "target_name": "napi-math",
      "sources": [ "src/napi-math.c" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "cflags": [ "-std=c99" ],
      "cflags_cc": [ "-std=c99" ]
    }
  ]
}