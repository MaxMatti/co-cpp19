
Product {
    Depends { name: "cpp" }
    Depends { name: "meta19" }

    files: [
        "None.h",
        "None.ostream.h",
        "Variant.equals.h",
        "Variant.h",
        "Variant.ostream.h",
    ]

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: [".."]
        Depends { name: "meta19" }
    }
}
