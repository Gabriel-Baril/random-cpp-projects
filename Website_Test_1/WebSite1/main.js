function objAnalyzer(a, tab) {
    for (var i = 0; i < Object.keys(a).length; i++) {
        if (typeof (a[Object.keys(a)[i]]) == "object") {
            console.log(a[Object.keys(a)[i]]);
            objAnalyzer(a[Object.keys(a)[i]], tab);
            return;
        }
        console.log(Object.keys(a)[i] + ": " + a[Object.keys(a)[i]] + "  (" + typeof (a[Object.keys(a)[i]]) + ")  in " + parent);
    }
}

var serie = {
    id: 1,
    "sex": "male",
    data: {
        "matricule": 167,
        test: {
            "adresse": 2456
        }
    }
}