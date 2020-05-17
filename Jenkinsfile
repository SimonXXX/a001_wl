pipeline {
	stages {
        stage('Build') {
            steps {
                sh 'echo this is the build'
            }
        }

        stage('Test') {
            steps {
                sh 'x64/Release/6771Assignment1.exe'
            }
        }
	}
}